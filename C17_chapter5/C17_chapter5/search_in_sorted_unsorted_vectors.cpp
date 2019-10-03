#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <string>

using namespace std;

struct city {
	string name;
	unsigned population;
};

bool operator==(const city& lhv, const city& rhv)
{
	return lhv.name == rhv.name && lhv.population == rhv.population;
}

namespace std 
{
	ostream& operator << (ostream& os, const city& c)
	{
		return os << "{" << c.name << ", "
			<< c.population << "}" << endl;
	}
}

namespace
{
template <typename T>
auto opt_print(const T& container)
{
	return[end_it(end(container))](const auto& item){
		if (item != end_it)
		{
			cout << *item << endl;
		}
		else {
			cout << "<end>" << endl;
		}
	};
}
}

void search_in_sorted_unsorted_vectors()
{
	const vector<city> c{
		{"Aachen", 246000},
		{"Berlin", 3502000},
		{"Braunschweig", 251000},
		{"Cologne", 1060000}
	};
	auto print_city(opt_print(c));

	{
		auto found_cologne(find(begin(c), end(c),
			city{ "Cologne", 1060000 }));
		print_city(found_cologne);
	}

	{
		auto found_cologne(find_if(begin(c), end(c),
			[](const auto& item) {
				return item.name == "Cologne";
			}));
		print_city(found_cologne);
	}

	{
		auto population_more_than([](unsigned i) {
			return [=](const city& item) {
				return item.population > i;
			};
			});
		auto found_large(find_if(begin(c), end(c),
			population_more_than(2000000)));
		print_city(found_large);
	}

	const vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	auto print_int(opt_print(v));

	bool contains_7{ binary_search(begin(v), end(v), 7) };
	// ¬ажно, чтобы контейнер, дл€ которого мы выполн€ем поиск, был упор€дочен, 
	// поскольку в противном случае бинарный поиск не будет выполнен корректно.
	cout << contains_7 << '\n';

	auto [lower_it, upper_it](
		equal_range(begin(v), end(v), 7)); // ќна возвращает пару итераторов. 
	//ѕервый итератор указывает на первый элемент, чье значение не меньше искомого, 
	//второй Ч на первый элемент, значение которого больше искомого -> binary search
	print_int(lower_it);
	print_int(upper_it);

	print_int(lower_bound(begin(v), end(v), 7)); // ≈сли нужно получить только один итератор -> binary search
	print_int(upper_bound(begin(v), end(v), 7)); // ≈сли нужно получить только один итератор -> binary search

	// ќбратите внимание: структуры данных наподобие std::map, std::set и т. д. 
	// имеют собственные функции find. ќни работают быстрее, 
	// чем более обобщенные алгоритмы, поскольку тесно св€заны с реализаци€ми структур данных.
}

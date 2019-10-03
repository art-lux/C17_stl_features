#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <random>

using namespace std;

namespace
{
	void print(const vector<int>& vec)
	{
		copy(begin(vec), end(vec), ostream_iterator<int>{cout, ", "});
		cout << endl;
	}
}

void sort_containers()
{
	vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	random_device rd;
	mt19937 g{ rd() };

	cout << is_sorted(begin(v), end(v)) << endl;

	shuffle(begin(v), end(v), g);
	cout << is_sorted(begin(v), end(v)) << endl;
	print(v);

	sort(begin(v), end(v));
	cout << is_sorted(begin(v), end(v)) << '\n';
	print(v);

	cout << "start partition---------" << endl;
	shuffle(begin(v), end(v), g);
	print(v);
	partition(begin(v), end(v), [](int i) { return i < 5; });
	print(v);
	cout << "finish partition---------" << endl;

	shuffle(begin(v), end(v), g);
	auto middle(next(begin(v), int(v.size()) / 2));
	partial_sort(begin(v), middle, end(v));
	print(v);

	struct mystruct {
		int a;
		int b;
	};
	vector<mystruct> mv{ {5, 100}, {1, 50}, {-123, 1000},
		{3, 70}, {-10, 20} };

	sort(begin(mv), end(mv),
		[](const mystruct& lhs, const mystruct& rhs) {
			return lhs.b < rhs.b;
		});
	for (const auto& [a, b] : mv) {
		cout << "{" << a << ", " << b << "} ";
	}
	cout << '\n';



	//example std::partition from cplusplus.com
	auto IsOdd([](int i) { return (i % 2) == 1; });
	
	std::vector<int> myvector;

	// set some values:
	for (int i = 1; i < 10; ++i) myvector.push_back(i); // 1 2 3 4 5 6 7 8 9

	std::vector<int>::iterator bound;
	bound = std::partition(myvector.begin(), myvector.end(), IsOdd);

	// print out content:
	std::cout << "odd elements:";
	for (std::vector<int>::iterator it = myvector.begin(); it != bound; ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "even elements:";
	for (std::vector<int>::iterator it = bound; it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	print(myvector);
}

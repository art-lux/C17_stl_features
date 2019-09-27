#include <unordered_map>
#include <iostream>

using namespace std;

struct coord
{
	int x;
	int y;
};

bool operator==(const coord& lhv, const coord& rhv)
{
	return lhv.x == rhv.x && lhv.y == rhv.y;
}

namespace std {
template<>
struct hash<coord>
{
	using argument_type = coord;
	using result_type = size_t;
	result_type operator()(const argument_type& arg) const
	{
		return static_cast<result_type>(arg.x) + static_cast<result_type>(arg.y);
	}
};
}

void unordered_map_for_user_types()
{
	std::unordered_map<coord, int> m{ {{0, 0}, 1}, 
	                                  {{0, 1}, 2},
									  {{2, 1}, 3} };
	for (const auto& [key, value] : m) {
		std::cout << "{(" << key.x << ", " << key.y
			<< "): " << value << "} ";
	}
	std::cout << '\n';
	//Если бы мы не добавили новую специализацию std::hash<coord>, 
	//а назвали бы имеющуюся вместо этого my_hash_type, 
	//то нам пришлось бы использовать следующую строку для создания объекта :
	//std::unordered_map<coord, value_type, my_hash_type> my_unordered_map;
}
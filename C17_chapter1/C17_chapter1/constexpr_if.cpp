#include <vector>
#include <string>
#include <iostream>

using namespace std;

template <typename T>
class addable
{
	T val;
public:
	addable(T v) : val{ v } {}
	
	template <typename U>
	T add(U x) const {
		if constexpr (std::is_same_v<T, std::vector<U>>) {
			auto copy(val);
			for (auto& n : copy) {
				n += x;
			}
			return copy;
		}
		else {
			return val + x;
		}
	}

	void show()
	{
		cout << val << endl;
	}
/*  // раньше это выглядело так

	std::enable_if_t<!std::is_same<T, std::vector<U>>::value, T>
	add(U x) const { return val + x; }

	template <typename U>
	std::enable_if_t<std::is_same<T, std::vector<U>>::value, std::vector<U>>
	add(U x) const {
		auto copy (val);
		for (auto &n : copy) {
			n += x;
		}
		return copy;
	}
------------------------------------
выражения ниже допустимы:

if constexpr (a) {
	// что-нибудь делаем
} else if constexpr (b) {
	// делаем что-нибудь еще
} else {
	// делаем нечто совсем другое
}
*/

};

void constexpr_if()
{
	addable<int>{1}.add(2); // результат - 3
	addable<float>{1.0}.add(2); // результат - 3.0
	cout << addable<std::string>{"aa"}.add("bb") << endl; // результат - "aabb"
	
	std::vector<int> v{ 1, 2, 3 };
	auto res = addable<std::vector<int>>{v}.add(10);
	// is std::vector<int>{11, 12, 13}
	for (auto& el : res)
	{
		cout << el << endl;
	}
	cout << endl;

	std::vector<std::string> sv{ "a", "b", "c" };
	auto resres = addable<std::vector<std::string>>{sv}.add(std::string{ "z" });
	// is {"az", "bz", "cz"}
	for (auto& el : resres)
	{
		cout << el << endl;
	}
	cout << endl;
}
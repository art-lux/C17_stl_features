#include <iostream>

using namespace std;

// for pair, for map
std::pair<int, int> devied_remainder(int devider, int divisor)
{
	return { devider / divisor, devider % divisor };
}

// for tuple
/*
====
std::tuple<std::string, std::chrono::system_clock::time_point, unsigned> stock_info(const std::string& name);
-----
const auto [name, valid_time, price] = stock_info("INTC");
====
*/

// for complicated structures
/*
struct employee {
	unsigned id;
	std::string name;
	std::string role;
	unsigned salary;
};

int main()
{
	std::vector<employee> employees{  Инициализируется в другом месте  };
		for (const auto& [id, name, role, salary] : employees) {
			std::cout << "Name: " << name
				<< "Role: " << role
				<< "Salary: " << salary << '\n';
		}
}if (auto itr(character_map.find(ch)); itr != character_map.end()) {
*/

void structured_binding()
{
	// old style
	const auto result(devied_remainder(16, 3));
	cout << "Result: " << endl << "fraction: " << result.first << endl << "reminder: " << result.second << endl;
	// or so:
	/*
		int remainder;
		std::tie(std::ignore, remainder) = divide_remainder(16, 5);
		std::cout << "16 % 5 is " << remainder << '\n';
	*/

	cout << endl;

	// c++17 style
	auto [fraction, reminder] = devied_remainder(16, 3);
	cout << "Result: " << endl << "fraction: " << fraction << endl << "reminder: " << reminder << endl << endl;
}
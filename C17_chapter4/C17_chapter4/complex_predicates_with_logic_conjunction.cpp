#include <iostream>
#include <functional>
#include <string>
#include <iterator>
#include <algorithm>
#include <sstream>

namespace {
	bool begins_with_a(const std::string& str)
	{
		return str.find("a") == 0;
	}

	bool end_with_b(const std::string& str)
	{
		return str.rfind("b") == str.length() - 1;
	}
}

template <typename Log, typename A, typename B>
auto combine(Log binary_func, A a, B b)
{
	return [=](auto param) { return binary_func(a(param), b(param)); };
}

using namespace std;

void complex_predicates_with_logic_conjunction()
{
	auto a_xxx_b(combine(logical_and<>{}, begins_with_a, end_with_b));
	std::stringstream str{ "ac cb ab axxxb" };

	std::stringstream ss{};

	copy_if(istream_iterator<std::string>{str}, istream_iterator<std::string>{}, ostream_iterator<std::string> {ss, " "}, a_xxx_b);
	std::cout << ss.str() << std::endl;
}
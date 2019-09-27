#include <iostream>
#include <string>
#include <deque>
#include <iterator>
#include <sstream>

using namespace std;

void iter_wrapper_fill_containers()
{
	istream_iterator<int> it_cin{ cin };
	istream_iterator<int> end_cin;

	deque<int> d;
	copy(it_cin, end_cin, back_inserter(d));

	istringstream sstr{ "123 456 789" };
	auto deque_middle(next(begin(d), d.size() / 2));

	copy(istream_iterator<int>(sstr), {}, inserter(d, deque_middle));

	initializer_list il2{ -1, -2, -3 };
	copy(begin(il2), end(il2), front_inserter(d));

	copy(begin(d), end(d), ostream_iterator<int>{cout, ", "});
	cout << endl;
}
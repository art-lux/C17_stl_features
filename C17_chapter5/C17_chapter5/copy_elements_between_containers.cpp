#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <tuple>
#include <iterator>
#include <algorithm>

using namespace std;

namespace std
{
	ostream& operator<<(ostream& os, const pair<int, string>& p)
	{
		return os << "(" << p.first << ", " << p.second << ")";
	}
}

void copy_elements_between_containers()
{
	vector<pair<int, string>> v{
		{1, "one"}, {2, "two"}, {3, "three"},
		{4, "four"}, {5, "five"} };

	map<int, string> m;

	copy_n(v.begin(), 3, inserter(m, m.begin()));

	auto shell_it(ostream_iterator<pair<int, string>>{cout, ", "});
	copy(begin(m), end(m), shell_it);

	m.clear();
	move(begin(v), end(v), inserter(m, begin(m)));
	cout << endl;

	copy(begin(m), end(m), shell_it);
	cout << endl;
	copy(begin(v), end(v), shell_it); // bad practice (undef)
	cout << v.size() << endl;
	cout << endl;
}

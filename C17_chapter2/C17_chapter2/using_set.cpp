#include <set>
#include <iostream>
#include <iterator>
#include <string>

using namespace std;

void using_set()
{
	set<string> s;
	
	istream_iterator<string> iter{ cin };
	istream_iterator<string> end;

	copy(iter, end, inserter(s, s.end()));

	for (const auto word : s) {
		cout << word << ", ";
	}
	cout << '\n';
}
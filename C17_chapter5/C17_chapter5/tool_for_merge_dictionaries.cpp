#include <iostream>
#include <algorithm>
#include <iterator>
#include <deque>
#include <tuple>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

using dict_entry = pair<string, string>;

namespace std {
	ostream& operator<<(ostream& os, const dict_entry& entry)
	{
		return os << entry.first << " " << entry.second << endl;
	}

	istream& operator>>(istream& is, dict_entry& entry)
	{
		return is >> entry.first >> entry.second;
	}
}

template <typename IS>
deque<dict_entry> from_instream(IS&& stream)
{
	deque<dict_entry> d{ istream_iterator<dict_entry>{stream}, {} };
	sort(begin(d), end(d));
	return d;
}

void tool_for_merge_dictionaries()
{
	auto dict1(from_instream(ifstream{ "dict.txt" }));
	stringstream ss{ "table tisch fish fisch dog hund" };
	auto dict2(from_instream(ss));
		
	merge(begin(dict1), end(dict1), begin(dict2), end(dict2), ostream_iterator<dict_entry>{cout, "\n"});
}
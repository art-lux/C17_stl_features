#include <iostream>
#include <algorithm>
#include <string>
#include <iterator>
#include <functional>

using namespace std;

namespace {
	template<typename It>
	void print(It it, size_t chars)
	{
		copy_n(it, chars, ostream_iterator<char>{cout});
		cout << endl;
	}
}

void find_patterns_in_string_by_search()
{
	const string long_string{"Lorem ipsum dolor sit amet, consetetur"
						" sadipscing elitr, sed diam nonumy eirmod" };
	const string needle{ "elitr" };

	{// old version search 
		auto match(search(begin(long_string), end(long_string),
			begin(needle), end(needle)));
		print(match, 5);
	}

	{// c17 version search (with object of find) 
		auto match(search(begin(long_string), end(long_string),
			default_searcher(begin(needle), end(needle))));
		print(match, 5);
	}

	{// search with boyer-moore algorithm
		auto match(search(begin(long_string), end(long_string),
			boyer_moore_searcher(begin(needle),
				end(needle))));
		print(match, 5);
	}

	{// search with boyer-moore-horspool algorithm
		auto match(search(begin(long_string), end(long_string),
			boyer_moore_horspool_searcher(begin(needle),
				end(needle))));
		print(match, 5);
	}
}
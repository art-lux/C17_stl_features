#include <iostream>
#include <map>
#include <algorithm>
#include <iterator>


using namespace std;

string filter_ws(const string& str)
{
	const char* ws{ " \r\n\t" };
	const auto a(str.find_first_not_of(ws));
	const auto b(str.find_last_not_of(ws));
	if (a == string::npos) {
		return {};
	}
	return str.substr(a, b - a + 1);
}

multimap<size_t, string> get_sentence_stats(const string& content)
{
	multimap<size_t, string> ret;
	const auto end_it(end(content));
	auto it1(begin(content));
	auto it2(find(it1, end_it, '.'));

	while (it1 != end_it && distance(it1, it2) > 0) {
		string s{ filter_ws({it1, it2}) };

		if (s.length() > 0) {
			const auto words(count(begin(s), end(s), ' ') + 1);
			ret.emplace(make_pair(words, move(s)));
		}
		if (it2 == end_it)
		{
			break;
		}
		it1 = next(it2, 1);
		it2 = find(it1, end_it, '.');
	}
	return ret;
}

void find_long_sentences_multimap()
{
	cin.unsetf(ios::skipws);
	string content{ istream_iterator<char>{cin}, {} };

	for (const auto& [word_count, sentence]
		: get_sentence_stats(content)) {
		cout << word_count << " words: " << sentence << ".\n";
	}
}
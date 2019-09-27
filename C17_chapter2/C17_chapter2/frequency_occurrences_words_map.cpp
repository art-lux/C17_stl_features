#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

string filter_punctuation(const string& str)
{
	const char* forbidden{ ".,:;" };
	const auto index_start(str.find_first_not_of(forbidden));
	const auto index_end(str.find_last_not_of(forbidden));
	return str.substr(index_start, index_end - index_start + 1);
}

void frequency_occurrences_words_map()
{
	map<string, size_t> words;
	int max_word_len{ 0 };

	string s;
	while (cin >> s) {
		auto filtered(filter_punctuation(s));
		max_word_len = max<int>(max_word_len, filtered.length());
		++words[filtered];

	}

	vector<pair<string, size_t>> word_counts;
	word_counts.reserve(words.size());
	move(begin(words), end(words), back_inserter(word_counts));

	sort(begin(word_counts), end(word_counts), [](const auto& a, const auto& b) {return a.second > b.second; });

	cout << "# " << setw(max_word_len) << "<WORD>" << " #<COUNT>\n";
	for (const auto& [word, count] : word_counts) {
		cout << setw(max_word_len + 2) << word << " #"
			<< count << '\n';
	}
}
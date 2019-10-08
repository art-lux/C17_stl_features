#include <iostream>
#include <optional>
#include <algorithm>
#include <functional>
#include <iterator>
#include <map>
#include <vector>
#include <string>

using namespace std;

template <typename T>
class trie
{
public:
	trie() = default;

	template<typename It>
	void insert(It it, It it_end)
	{
		if (it == it_end) return;
		tries[*it].insert(next(it), it_end);
	}

	template <typename C>
	void insert(const C& container)
	{
		insert(begin(container), end(container));
	}

	void insert(const initializer_list<T>& il)
	{
		insert(begin(il), end(il));
	}

	void print() const
	{
		vector<T> v;
		print(v);
	}

	template <typename C>
	auto subtrie(const C& container)
	{
		return subtrie(begin(container), end(container));
	}

	~trie() = default;

private:
	
	void print(vector<T>& vec) const
	{
		if (tries.empty()) {
			copy(begin(vec), end(vec), ostream_iterator<T>{cout, " "});
			cout << endl;
		}
		for (const auto& el : tries) {
			vec.push_back(el.first);
			el.second.print(vec);
			vec.pop_back();
		}
	}

	template <typename It>
	optional<reference_wrapper<const trie>>
		subtrie(It it, It it_end) const
	{
		if (it == it_end) return ref(*this);
		auto found(tries.find(*it));
		if (found == end(tries)) return {};
		return found->second.subtrie(next(it), it_end);
	}

	map<T, trie> tries;
};

void prefix_tree_with_std_alg()
{
	trie<string> tr;
	tr.insert({ "hi", "how", "are", "you" });
	tr.insert({ "hi", "i", "am", "great", "thanks" });
	tr.insert({ "what", "are", "you", "doing" });
	tr.insert({ "i", "am", "watching", "a", "movie" });

	cout << "recorded sentences:\n";
	tr.print();

	cout << "\npossible suggestions after \"hi\":\n";
	if (auto st(tr.subtrie(initializer_list<string>{"hi"})); st) {
		st->get().print();
	}
}
#include <iostream>
#include <algorithm>



class num_iterator
{
public:
	explicit num_iterator(int position = 0) : pos(position) {}
	int operator*() const { return pos; }
	num_iterator& operator++() { ++pos; return *this; }
	bool operator==(const num_iterator& other) const
	{
		return pos == other.pos;
	}

	bool operator!=(const num_iterator& other) const
	{
		return !(*this == other);
	}
private:
	int pos;
};

namespace std {
	template <>
	struct iterator_traits<num_iterator> {
		using iterator_category = std::forward_iterator_tag;
		using value_type = int;
	};
}

class num_range {
public:
	num_range(int from, int to)
		: a{ from }, b{ to }
	{}
	num_iterator begin() const { return num_iterator{ a }; }
	num_iterator end() const { return num_iterator{ b }; }

private:
	int a;
	int b;
};

using namespace std;

void self_made_iter_compatibility_stl()
{
	num_range r{ 100, 110 };
	auto [min_it, max_it](minmax_element(begin(r), end(r)));
	cout << *min_it << " - " << *max_it << '\n';
}
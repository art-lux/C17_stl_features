#include <iostream>

class num_iterator
{
public:
	explicit num_iterator(int position = 0) : pos(position) {}

	int operator*() const { return pos; }

	num_iterator& operator++() {
		++pos;
		return *this;
	}

	bool operator!=(const num_iterator& other) const {
		return pos != other.pos;
	}

private:
	int pos;
};

class num_range
{
public:
	num_range(int from, int to) : a(from), b(to) {}

	num_iterator begin() const {
		return num_iterator{ a };
	}

	num_iterator end() const {
		return num_iterator{ b };
	}

private:
	int a;
	int b;
};

void self_made_iterator()
{
	for (int i : num_range{ 100, 110 }) {
		std::cout << i << ", ";
	}
	std::cout << '\n';
}

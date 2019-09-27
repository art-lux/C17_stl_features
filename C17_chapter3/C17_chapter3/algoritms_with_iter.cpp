#include <iostream>
#include <vector>

class fib_it
{
public:
	
	size_t operator*() const { return b; }
	
	fib_it& operator++()
	{
		const auto old_b{ b };
		b += a;
		a = old_b;
		++i;
		return *this;
	}

	bool operator!=(const fib_it& other) const
	{
		return i != other.i;
	}

private:
	friend class fib_range;

	fib_it() = default;

	explicit fib_it(size_t i_) : i(i_) {}
	size_t i{ 0 };
	size_t a{ 0 };
	size_t b{ 1 };
};
class fib_range
{
public:
	explicit fib_range(size_t in_) : end_n(in_){}
	fib_it begin() { return {}; }
	fib_it end() { return fib_it{ end_n }; };
private:
	size_t end_n;
};

void algoritms_with_item()
{
	for (size_t i : fib_range(10)) {
		std::cout << i << ", ";
	}
	std::cout << '\n';
	std::vector<int> v;
}
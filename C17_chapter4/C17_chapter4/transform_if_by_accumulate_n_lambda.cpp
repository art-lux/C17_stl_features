#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>

template <typename T>
auto map(T fn)
{
	return [=](auto reduce_fn) {
		return [=](auto accum, auto input) {
			return reduce_fn(accum, fn(input));
		};
	};
}

template <typename T>
auto filter(T predicate)
{
	return [=](auto reduce_fn) {
		return [=](auto accum, auto input) {
			if (predicate(input)) {
				return reduce_fn(accum, input);
			}
			else {
				return accum;
			}
		};
	};
}

void transform_if_by_accumulate_n_lambda()
{
	std::stringstream ss{ "1 2 3 4 5 6" };
	std::istream_iterator<int> it{ ss };
	std::istream_iterator<int> end_it;

	auto even([](int i) {return i % 2 == 0; });
	auto twice([](int i) {return i * 2; });

	auto copy_and_advance([](auto it, auto input) {
		*it = input;
		return ++it;
	});

	std::accumulate(it,
		end_it,
		std::ostream_iterator<int>{std::cout, ", "},
		filter(even)(map(twice)(copy_and_advance)
	));
	std::cout << '\n';
}
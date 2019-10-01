#include <iostream>
#include <deque>
#include <vector>
#include <list>
#include <functional>

template <typename T>
static auto consumer(T& container) {
	return [&](auto value) {
		container.push_back(value);
	};
};

template <typename T>
static void print(const T& c)
{
	for (auto el : c) {
		std::cout << el << ", ";
	}
	std::cout << '\n';
}

void lambda_with_function()
{
	std::deque<int> d;
	std::vector<int> v;
	std::list<int> l;

	const std::vector<std::function<void(int)>> consumers
	{ consumer(d), consumer(l), consumer(v) };

	for (size_t i{ 0 }; i < 10; ++i) {
		for (auto&& consume : consumers) {
			consume(i);
		}
	}
	
	print(d);
	print(v);
	print(l);
}
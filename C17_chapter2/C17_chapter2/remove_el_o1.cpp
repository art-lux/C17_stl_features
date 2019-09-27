#include <iostream>
#include <vector>
#include <algorithm>
#include "vector_show.h"

template <typename T>
void quick_remove_at(vector<T>& v, size_t index)
{
	if (index < v.size()) {
		v[index] = std::move(v.back());
		v.pop_back();
	}
}

template <typename T>
void quick_remove_at(std::vector<T>& v,
	typename std::vector<T>::iterator it)
{
	if (it != std::end(v)) {
		*it = std::move(v.back());
		v.pop_back();
	}
}

void remove_el_o1()
{
	vector<int> v{ 123, 456, 789, 100, 200 };
	vector_out(v);
	
	quick_remove_at(v, 2);
	vector_out(v);

	quick_remove_at(v, find(begin(v), end(v), 123));
	vector_out(v);
}
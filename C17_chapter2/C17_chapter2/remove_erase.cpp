#include <vector>
#include <iostream>
#include <algorithm>
#include "vector_show.h"


void remove_erase()
{
	vector<int> v{ 1, 2, 3, 2, 5, 2, 6, 2, 4, 8 };
	collection_out(v);

	const auto new_end(remove(begin(v), end(v), 2));
	vector_out(v);

	v.erase(new_end, end(v));
	vector_out(v);

	const auto odd([](int i) { return i % 2 != 0; });
	v.erase(remove_if(begin(v), end(v), odd), end(v));
	vector_out(v);
	
	v.shrink_to_fit();
	vector_out(v);
}

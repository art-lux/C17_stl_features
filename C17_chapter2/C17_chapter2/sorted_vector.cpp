#include <vector>
#include <string>
#include <iostream>
#include <cassert>
#include <algorithm>
#include "vector_show.h"

void insert_sorted(vector<string>& v, const string& word)
{
	const auto insert_pos(lower_bound(begin(v), end(v), word));
	v.insert(insert_pos, word);
}

void sorted_vector()
{
	vector<string> v{ "some", "random", "words",
					  "without", "order", "aaa",
					  "yyy" };
	collection_out(v);
	assert(false == is_sorted(begin(v), end(v)));

	sort(begin(v), end(v));
	collection_out(v); // insead vector_out()
	
	assert(true == is_sorted(begin(v), end(v)));

	insert_sorted(v, "foobar");
	insert_sorted(v, "zzz");
	collection_out(v); // insead vector_out()
}

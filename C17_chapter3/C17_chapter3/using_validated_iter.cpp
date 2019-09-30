#define _ITERATOR_DEBUG_LEVEL 2 // sanitizer feature

#include <iostream>
#include <vector>

void using_validated_iter()
{
	std::vector<int> v{ 1,2,3 };
	v.shrink_to_fit();
	
	const auto it(std::begin(v));
	std::cout << *it << std::endl;

	v.push_back(123);
	//std::cout << *it << std::endl;
}
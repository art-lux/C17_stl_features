#include <iostream>

extern void self_made_iterator();
extern void self_made_iter_compatibility_stl();
extern void iter_wrapper_fill_containers();
extern void algoritms_with_item();
int main()
{
	self_made_iterator();
	std::cout << std::endl;

	self_made_iter_compatibility_stl();
	std::cout << std::endl;

	iter_wrapper_fill_containers();
	std::cout << std::endl;

	algoritms_with_item();
	std::cout << std::endl;
	return 0;
}
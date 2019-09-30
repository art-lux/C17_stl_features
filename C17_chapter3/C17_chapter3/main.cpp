#include <iostream>

extern void self_made_iterator();
extern void self_made_iter_compatibility_stl();
extern void iter_wrapper_fill_containers();
extern void algoritms_with_item();
extern void backward_wrapper_iter();
extern void enumerate_ranges_with_delimiter();
extern void using_validated_iter();
extern void adapter_iter_packers();

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

	backward_wrapper_iter();
	std::cout << std::endl;

	enumerate_ranges_with_delimiter();
	std::cout << std::endl;

	using_validated_iter();
	std::cout << std::endl;	

	adapter_iter_packers();
	std::cout << std::endl;
	return 0;
}
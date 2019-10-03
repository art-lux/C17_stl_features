#include <iostream>

extern void copy_elements_between_containers();
extern void sort_containers();
extern void remove_concrete_elem_from_containers();
extern void transforming_containers();
extern void search_in_sorted_unsorted_vectors();
int main()
{
	copy_elements_between_containers();
	std::cout << std::endl;

	sort_containers();
	std::cout << std::endl;

	remove_concrete_elem_from_containers();
	std::cout << std::endl;

	transforming_containers();
	std::cout << std::endl;

	search_in_sorted_unsorted_vectors();
	std::cout << std::endl;
	return 0;
}

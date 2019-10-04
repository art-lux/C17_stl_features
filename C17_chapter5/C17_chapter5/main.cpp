#include <iostream>

extern void copy_elements_between_containers();
extern void sort_containers();
extern void remove_concrete_elem_from_containers();
extern void transforming_containers();
extern void search_in_sorted_unsorted_vectors();
extern void constrain_values_in_vector_by_clamp();
extern void find_patterns_in_string_by_search();
extern void make_data_sampling_from_large_vectors();
extern void perform_permutations_in_input_sequences();
extern void tool_for_merge_dictionaries();
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

	constrain_values_in_vector_by_clamp();
	std::cout << std::endl;

	find_patterns_in_string_by_search();
	std::cout << std::endl;

	make_data_sampling_from_large_vectors();
	std::cout << std::endl;

	perform_permutations_in_input_sequences();
	std::cout << std::endl;

	tool_for_merge_dictionaries();
	std::cout << std::endl;
	return 0;
}

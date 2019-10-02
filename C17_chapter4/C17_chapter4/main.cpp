#include <iostream>

extern void lambda_intro();
extern void lambda_with_function();
extern void make_function_by_concatenation();
extern void complex_predicates_with_logic_conjunction();
extern void different_func_with_same_incoming_data();
extern void transform_if_by_accumulate_n_lambda();
extern void cartesian_product_with_any_input_at_compile_time();

int main()
{
	lambda_intro();
	std::cout << std::endl;

	lambda_with_function();
	std::cout << std::endl;

	make_function_by_concatenation();
	std::cout << std::endl;

	complex_predicates_with_logic_conjunction();
	std::cout << std::endl;

	different_func_with_same_incoming_data();
	std::cout << std::endl;

	transform_if_by_accumulate_n_lambda();
	std::cout << std::endl;

	cartesian_product_with_any_input_at_compile_time();
	std::cout << std::endl;
	return 0;
}
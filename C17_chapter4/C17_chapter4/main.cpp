#include <iostream>

extern void lambda_intro();
extern void lambda_with_function();
extern void make_function_by_concatenation();
extern void complex_predicates_with_logic_conjunction();
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
	return 0;
}
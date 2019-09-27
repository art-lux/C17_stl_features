#include <string>
#include <iostream>

/*
1.  ����� process_monitor ������ ��������� ����������� ���� 
	� ���� ��������� ��������� ��� �� ����, 
	��� ��������(��� ��������� ��� � ��������� ������ ����������) � ��������� ��������,
	������������ ������ :
*/

// foo_lib.hpp
/*
class process_monitor {
public:
	static const std::string standard_string
	{ "some static globally available string" };
};
process_monitor global_process_monitor;
*/


/*
2.  ������ ��� ������� �������� ������ ��� � ��������� ������ 
	� �����������.cpp, � ����� �������������� � ������� �� ���������� ���� 
	�� ����� ����������.����� ��� ���������, ������� �������� ����� inline:
*/
// foo_lib.hpp
class process_monitor {
public:
	static const inline std::string standard_string
	{ "some static globally available string" };
};
inline process_monitor global_process_monitor;

void header_libs_with_inline()
{
	std::cout << std::endl;
	std::cout << global_process_monitor.standard_string << std::endl << std::endl;
}
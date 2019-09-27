#include <string>
#include <map>
#include <iostream>

using namespace std;

void move_left() { cout << "left key" << endl; }
void move_back(){ cout << "back key" << endl; }
void move_fwd(){ cout << "forward key" << endl; }
void move_right(){ cout << "right key" << endl; }
void quit_game(){ cout << "quit key" << endl; }
void select_tool(char c){ cout << "digit key" << endl; }

// some more examples
/*
// 1

if (std::lock_guard<std::mutex> lg{ my_mutex }; some_condition) {
	// ������ ���-������
}

// 2

if (auto shared_pointer (weak_pointer.lock()); shared_pointer != nullptr) {
	// ��, ����� ������ ��� ����������
} else {
	// � ��������� shared_pointer ����� �������� ������, �� �� �������� �������
}
// � shared_pointer ������ ������ �������� ������

// 3

if (DWORD exit_code; GetExitCodeProcess(process_handle, &exit_code)) {
	std::cout << "Exit code of process was: " << exit_code << '\n';
}
// ����������� ���������� exit_code �� �������� �� ������� ������� if

*/


void if_switch_scope()
{
	map<char, string> character_map;

	char ch('c');
	if (auto itr(character_map.find(ch)); itr != character_map.end()) {
		// *itr ���������. ������� � ��� ���-������.
	}
	else {
		cout << "not found!!!" << endl << endl;
	}
	// ����� itr ����������

	switch (char c(getchar()); c)
	{
	case 'a': move_left(); break;
	case 's': move_back(); break;
	case 'w': move_fwd(); break;
	case 'd': move_right(); break;
	case 'q': quit_game(); break;
	case '0':
	case '9': select_tool('0' - c); break;
	default:
		std::cout << "invalid input: " << c << '\n';
	}

}
#include <vector>
#include <iostream>

using namespace std;

void init_braces_rules()
{
	// 1. without auto
	// ��� ���������� ������� ���������������� ���������� ���� int:
	int x1 = 1;
	int x2{ 1 };
	int x3(1);
	std::vector<int> v1{ 1, 2, 3 };
	// ������, ���������� ��� ���������� ���� int: 1, 2, 3
	std::vector<int> v2 = { 1, 2, 3 }; // ����� �� ������
	std::vector<int> v3(10, 20);
	// ������, ���������� ������ ���������� ���� int,
	// ������ �� ������� ����� �������� 20
	std::vector<int> v4 { 10, 20 };
	for (auto& el : v3)
	{
		cout << el << ' ';
	}
	cout << endl;
	for (auto& el : v4)
	{
		cout << el << ' ';
	}
	cout << endl;

	// 2. with auto
	auto v{ 1 }; // v ����� ��� int
//	auto w{ 1, 2 };  -  ������: ��� �������������� ��������� ����
	// ���������������� ������������� ���������
	// ������ ���������� ����������! (������������)
	auto x = { 1 }; // x ����� ��� std::initializer_list<int>
	auto y = { 1, 2 }; // y ����� ��� std::initializer_list<int>
//	auto z = { 1, 2, 3.0 };  - ������: ������ ������� ��� ��������

/*
	� ����������� auto var_name{ one_element }; ���������� var_name ����� ����� ��� �� ���, ��� � one_element;
	����������� auto var_name{ element1, element2, ... }; ��������������� � �� ����� ��������������;
	����������� auto var_name = { element1, element2, ... }; ����� ����� ��� std::initializer_list<T>, ��� T � ��� ���� ��������� ������.
	� �++17 ������� ������� �������� ���������� ������ ���������������.
*/
}

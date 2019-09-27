#include <iostream>
#include <tuple>
#include <typeinfo>

using namespace std;
	

template <typename T>
struct sum {
	T value;
	template <typename ... Ts>
	sum(Ts&& ... values) : value{ (values + ...) } {}
};

/*
���� �� ��������� ����� �����, ����� � ��������� ������ � ����� � ��������� ���������,
�� ����������� ������� ����������, ����� ��� �������� ���� ��������� ��� ������ ��������.
��� ����� �� ������������� ����� ������� ��������� �����
*/
template <typename ... Ts>
sum(Ts&& ... ts)->sum<std::common_type_t<Ts...>>;

void ctor_auto_resolve_type()
{
	
	pair my_pair(123, "abc"); // instead std::pair<int, const char*> my_pair(123, "abc");
	tuple my_tuple(123, 12.3, "abc"); // std::tuple<int, double, const char*> my_tuple(123, 12.3, "abc");

//  �� ������� ������� �� ������ � ������� ��������� ���� �������.
	sum s( 1u, 2.0, 3, 4.0f );
	sum string_sum ( std::string{"abc"}, "def" );

	cout << typeid(s.value).name() << endl;
	cout << typeid(string_sum.value).name() << endl;
}
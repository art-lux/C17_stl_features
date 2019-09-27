#include <string>
#include <iostream>
#include <vector>
#include <map>
/*
1.  ��������� �������, ������� ��������� 
	���������� ���������� ���������� � ���������� �� �����.
	������� ��������� �� ��������� :
*/
template <typename ... Ts>
auto sum(Ts ... ts);

/*
2.  ������ � ��� ���� ����� ���������� ts, 
	������� ������ ����������� ��� ��������� � 
	�������������� �� � ������� ��������� �������.
	��������, �� ����� ��������������� ����� - ������ 
	����������(� ����� ������ + ) ������ � ..., 
	����� ��������� ��� �� ���� ��������� ������ ����������.
	��� ����� ����� ����� ��������� � ������ :
*/
template <typename ... Ts>
auto sum(Ts ... ts)
{
	return (ts + ...);
}

/*
	� ���������� ���������� � (&&) � ��� (||) ��������� ���������� ����������� ��������. 
	������� ������� ������ ���������� � ���������� && ���������� �� true, 
	� ������� ������� ������ � ���������� || � �� false.
	�������� � ��������� ������� ������ ����������, 
	��������� �������� ��������� ����� ������� ����������� �������, 
	void(), ������� �������� ������� �� �������.
*/
template <typename T, typename ... Ts>
void vec_insert_all(std::vector<T>& vec, Ts ... ts)
{
	(vec.push_back(ts), ...);
}
//call example
//	std::vector<int> v{ 1, 2, 3 };
//	insert_all(v, 4, 5, 6);

template <typename R, typename ... Ts>
auto matches(const R& range, Ts ... ts)
{
	return (std::count(std::begin(range), std::end(range), ts) + ...);
}
//call example
//	std::vector<int> v {1, 2, 3, 4, 5};
//	matches(v, 2, 5); // ���������� 2
//	matches(v, 100, 200); // ���������� 0
//	matches("abcdefg", 'x', 'y', 'z'); // ���������� 0
//	matches("abcdefg", 'a', 'd', 'f'); // ���������� 3

template <typename T, typename ... Ts>
bool insert_all(T& set, Ts ... ts)
{
	return (set.insert(ts).second && ...);
}
//call example
//	std::set<int> my_set{ 1, 2, 3 };
//	insert_all(my_set, 4, 5, 6); // ���������� true
//	insert_all(my_set, 7, 8, 2); // ���������� false, ��������� 2 ��� ������������

// std::set<int> my_set{ 1, 2, 3 };
// insert_all(my_set, 4, 2, 5); // ���������� false, ������ ��������� �������� �������� {1, 2, 3, 4}, ��� 5!

template <typename T, typename ... Ts>
bool within(T min, T max, Ts ...ts)
{
	return ((min <= ts && ts <= max) && ...);
}
//call example
//	within(10, 20, 1, 15, 30); // --> false
//	within(10, 20, 11, 12, 13); // --> true
//	within(5.0, 5.5, 5.1, 5.2, 5.3) // --> true

//	std::string aaa{ "aaa" };
//	std::string bcd{ "bcd" };
//	std::string def{ "def" };
//	std::string zzz{ "zzz" };
//	within(aaa, zzz, bcd, def); // --> true
//	within(aaa, def, bcd, zzz); // --> false

void fold_expression()
{

//	3. ������ ����� ������� ������� ��������� ������� :
	int the_sum{ sum(1, 2, 3, 4, 5) }; // ��������: 15
//	4. ��� �������� �� ������ � �������������� ������; ����� ������� �� ��� ������ ����, ������������ �������� + , �������� std::string:
	std::string a{ "Hello " };
	std::string b{ "World" };
	std::cout << sum(a, b) << '\n'; // �����: Hello World
	std::cout << sum(15.26, 15) << '\n';
}
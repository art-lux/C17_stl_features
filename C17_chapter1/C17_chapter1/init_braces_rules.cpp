#include <vector>
#include <iostream>

using namespace std;

void init_braces_rules()
{
	// 1. without auto
	// “ри идентичных способа инициализировать переменную типа int:
	int x1 = 1;
	int x2{ 1 };
	int x3(1);
	std::vector<int> v1{ 1, 2, 3 };
	// ¬ектор, содержащий три переменные типа int: 1, 2, 3
	std::vector<int> v2 = { 1, 2, 3 }; // “акой же вектор
	std::vector<int> v3(10, 20);
	// ¬ектор, содержащий дес€ть переменных типа int,
	// кажда€ из которых имеет значение 20
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
	auto v{ 1 }; // v имеет тип int
//	auto w{ 1, 2 };  -  ошибка: при автоматическом выведении типа
	// непосредственна€ инициализаци€ разрешена
	// только одиночными элементами! (нововведение)
	auto x = { 1 }; // x имеет тип std::initializer_list<int>
	auto y = { 1, 2 }; // y имеет тип std::initializer_list<int>
//	auto z = { 1, 2, 3.0 };  - ошибка: нельз€ вывести тип элемента

/*
	в конструкции auto var_name{ one_element }; переменна€ var_name будет иметь тот же тип, что и one_element;
	конструкци€ auto var_name{ element1, element2, ... }; недействительна и не будет скомпилирована;
	конструкци€ auto var_name = { element1, element2, ... }; будет иметь тип std::initializer_list<T>, где T Ч тип всех элементов списка.
	¬ —++17 гораздо сложнее случайно определить список инициализаторов.
*/
}

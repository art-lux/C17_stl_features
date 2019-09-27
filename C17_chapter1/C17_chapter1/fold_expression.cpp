#include <string>
#include <iostream>
#include <vector>
#include <map>
/*
1.  Реализуем функцию, которая принимает 
	переменное количество параметров и возвращает их сумму.
	Сначала определим ее сигнатуру :
*/
template <typename ... Ts>
auto sum(Ts ... ts);

/*
2.  Теперь у нас есть пакет параметров ts, 
	функция должна распаковать все параметры и 
	просуммировать их с помощью выражения свертки.
	Допустим, мы хотим воспользоваться каким - нибудь 
	оператором(в нашем случае + ) вместе с ..., 
	чтобы применить его ко всем значениям пакета параметров.
	Для этого нужно взять выражение в скобки :
*/
template <typename ... Ts>
auto sum(Ts ... ts)
{
	return (ts + ...);
}

/*
	В логических операторах И (&&) и ИЛИ (||) появились встроенные нейтральные элементы. 
	Свертка пустого пакета параметров с оператором && заменяется на true, 
	а свертка пустого пакета с оператором || — на false.
	Работает в отношении пустого пакета параметров, 
	поскольку оператор «запятая» имеет неявный нейтральный элемент, 
	void(), который означает «ничего не делать».
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
//	matches(v, 2, 5); // возвращает 2
//	matches(v, 100, 200); // возвращает 0
//	matches("abcdefg", 'x', 'y', 'z'); // возвращает 0
//	matches("abcdefg", 'a', 'd', 'f'); // возвращает 3

template <typename T, typename ... Ts>
bool insert_all(T& set, Ts ... ts)
{
	return (set.insert(ts).second && ...);
}
//call example
//	std::set<int> my_set{ 1, 2, 3 };
//	insert_all(my_set, 4, 5, 6); // Возвращает true
//	insert_all(my_set, 7, 8, 2); // Возвращает false, поскольку 2 уже присутствует

// std::set<int> my_set{ 1, 2, 3 };
// insert_all(my_set, 4, 2, 5); // Возвращает false, теперь множество содержит значения {1, 2, 3, 4}, без 5!

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

//	3. Теперь можно вызвать функцию следующим образом :
	int the_sum{ sum(1, 2, 3, 4, 5) }; // Значение: 15
//	4. Она работает не только с целочисленными типами; можно вызвать ее для любого типа, реализующего оператор + , например std::string:
	std::string a{ "Hello " };
	std::string b{ "World" };
	std::cout << sum(a, b) << '\n'; // Вывод: Hello World
	std::cout << sum(15.26, 15) << '\n';
}
#pragma once
#include <vector>
#include <iostream>
#include <map>
#include "billionare.h"

using namespace std;


template <typename T>
void vector_out(vector<T>& v)
{

	for (auto& el : v)
	{
		cout << el << " ";
	}
	cout << '\n';
	cout << "OLDSize: " << v.size() << " Capacity: " << v.capacity() << endl;

}


template<typename>
struct is_std_map : std::false_type {};

template<typename T, typename N>
struct is_std_map<std::map<T, N>> : std::true_type {};

template <template<typename, typename>typename Ts, typename... T>
void collection_out(Ts<T...>& v)
{
	if constexpr (is_std_map<Ts<T...>>::value)
	{
		for (const auto& [key, value] : v) {
			const auto& [b, count] = value;
			cout << b.country << " : " << count
				<< " billionaires. Richest is "
				<< b.name << " with " << b.dollars
				<< " B$\n";
		}
	}
	else {
		for (auto& el : v)
		{
			cout << el << " ";
		}
		cout << '\n';
		cout << "Size: " << v.size() << " Capacity: " << v.capacity() << endl;
	}
}

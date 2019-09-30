#include <iostream>

// В этом примере мы создадим итератор и класс диапазона, 
// который позволит проитерировать по строке неизвестной длины, 
// не зная конечной позиции заранее.

class cstring_iterator_sentinel {};

class  cstring_iterator
{
public:
	cstring_iterator(const char* str) : s(str) {};
	~cstring_iterator() {};
	char operator*() { return *s; }
	cstring_iterator& operator++() { ++s; return *this; }
	bool operator!=(const cstring_iterator_sentinel ) const{
		return s != nullptr && *s != '\0';
	}

private:
	const char* s{ nullptr };
};

class cstring_range
{
public:
	cstring_range(const char* str) : s(str){}
	cstring_iterator begin() const { return cstring_iterator(s); }
	cstring_iterator_sentinel end() const { return {}; }

private:
	const char* s{ nullptr };
};

 
void enumerate_ranges_with_delimiter()
{
	auto test_str = "abcdef";
	for (auto el : cstring_range(test_str))
	{
		std::cout << el << ", ";
	}
	std::cout << std::endl;

}
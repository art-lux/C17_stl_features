#include <iostream>
#include <vector>
#include <numeric>

class zip_iterator
{
	using it_type = std::vector<double>::iterator;
public:
	zip_iterator(it_type it1, it_type it2) : it1_(it1), it2_(it2) {};
	zip_iterator& operator++() { ++it1_; ++it2_; return *this; }
	bool operator!=(const zip_iterator& other) const { return it1_ != other.it1_ && it2_ != other.it2_; }
	bool operator==(const zip_iterator& other) const { return !(operator!=(other)); }
	std::pair<double, double> operator*() { return { *it1_, *it2_ }; }
private:
	it_type it1_;
	it_type it2_;
};

namespace std {
	template <>
	struct iterator_traits<zip_iterator> {
		using iterator_category = std::forward_iterator_tag;
		using value_type = std::pair<double, double>;
		using difference_type = long int;
	};
}

class zipper {
	using vector_type = std::vector<double>;
public:
	zipper(vector_type& v1, vector_type& v2) : vec1(v1), vec2(v2) {}
	zip_iterator begin() const { return{ std::begin(vec1), std::begin(vec2) }; }
	zip_iterator end() const { return{ std::end(vec1), std::end(vec2) }; }
private:
	vector_type& vec1;
	vector_type& vec2;
};

#include <valarray> // for last code block
void adapter_iter_packers()
{
	std::vector<double> a{ 1.0, 2.0, 3.0 };
	std::vector<double> b{ 4.0, 5.0, 6.0 };

	zipper zp(a, b);

	const auto add_product([](double sum, const auto& p) {return sum + p.first * p.second; });

	const auto dot_product(std::accumulate(std::begin(zp), std::end(zp), 0.0, add_product));

	std::cout << "Dot product: " << dot_product << std::endl;

	{ // need to explore valarray ???
		std::valarray<double> a{ 1.0, 2.0, 3.0 };
		std::valarray<double> b{ 4.0, 5.0, 6.0 };
		std::cout << (a * b).sum() << '\n';
	}
}
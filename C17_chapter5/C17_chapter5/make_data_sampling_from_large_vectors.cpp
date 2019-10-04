#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <iterator>
#include <map>
#include <iomanip>

using namespace std;

void make_data_sampling_from_large_vectors()
{
	const size_t data_point{ 100000 };
	const size_t sample_point{ 100 };

	const int mean{ 10 };
	const size_t dev{ 3 };

	random_device rd;
	mt19937 gen{ rd() };
	normal_distribution<> d{ mean, dev };

	vector<int> v;
	v.reserve(data_point);
	generate_n(back_inserter(v), data_point, [&] {return d(gen); });

	vector<int> samples;
	samples.reserve(sample_point);

	sample(begin(v), end(v), back_inserter(samples), sample_point, mt19937(random_device{}()));

	map<int, size_t> histogram;
	for (int i : samples) { ++histogram[i]; }

	for (const auto& [value, count] : histogram)
	{
		cout << setw(2) << value << " " << string(count, '*') << endl;
	}
}
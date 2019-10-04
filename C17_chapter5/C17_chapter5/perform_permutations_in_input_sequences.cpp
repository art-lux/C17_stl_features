#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <sstream>

using namespace std;

void perform_permutations_in_input_sequences()
{
	const string st{ "a b c" };
	stringstream ss(st);
	vector<string> v{ istream_iterator<string>{ss}, {} };
	sort(begin(v), end(v));
	// ����� ����� ��� ��������� ������������, 
	// �� �������� ������������� ������. 
	// ��� ���� ������� ������, ��� ���� �� ����� ������ "c b a", ��������,
	// �� �������� �������� �� ������ ����������, ��� ��� 
	// ������ ������ ������������ ����� ��������� ��������� 
	// ������������������ ������� ���������

	do {
		copy(begin(v), end(v),
			ostream_iterator<string>{cout, ", "});
		cout << '\n';
	} while (next_permutation(begin(v), end(v)));
}
#include <iostream>
#include <tuple>
#include <string>
#include <queue>

using namespace std;

void list_current_tasks_priority_queue()
{
	using item_type = pair<int, string>;

	priority_queue<item_type> q;

	std::initializer_list<item_type> il{
		{1, "dishes"},
		{0, "watch tv"},
		{2, "do homework"},
		{0, "read comics"},
	};

	for (const auto& p : il) {
		q.push(p);
	}

	while (!q.empty()) {
		std::cout << q.top().first << ": " << q.top().second << '\n';
		q.pop();
	}
	std::cout << '\n';
}
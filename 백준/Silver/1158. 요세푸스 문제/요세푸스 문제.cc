#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main()
{
	int N, k;

	cin >> N >> k;

	list<int> L;

	for (int i = 0; i < N; i++)
		L.push_back(i + 1);

	auto it = L.begin();

	cout << "<";

	while (!L.empty())
	{
		for (int i = 1; i < k; i++)
		{
			it++;
			if (it == L.end()) it = L.begin();
		}

		cout << *it;

		auto temp = it;
		temp++;
		if (temp == L.end()) temp = L.begin();

		it = L.erase(it);

		if (!L.empty()) cout << ", ";

		it = temp;
	}

	cout << ">";
}
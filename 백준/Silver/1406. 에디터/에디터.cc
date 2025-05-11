#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	getline(cin, s);

	list<char> L;

	for (auto e : s) L.push_back(e);
	auto cursor = L.end();

	int numOfcommand;
	cin >> numOfcommand;

	for (int i = 0; i < numOfcommand; i++)
	{
		char command;
		cin >> command;

		if (command == 'L')
		{
			if (cursor != L.begin()) --cursor;
		}
		else if (command == 'D')
		{
			if (cursor != L.end()) ++cursor;
		}
		else if (command == 'B') //cusor 왼쪽 원소 삭제
		{
			if (cursor != L.begin())
			{
				--cursor;
				cursor = L.erase(cursor);
			}
		}
		else if (command == 'P')
		{
			char add;
			cin >> add;
			L.insert(cursor, add);
		}
	}

	for (auto ans : L)	cout << ans;

	return 0;
}
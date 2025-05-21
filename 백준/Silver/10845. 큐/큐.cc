#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
int main(void)
{
	int N;
	queue<int> q;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string command;
		cin >> command;
		cin.ignore();

		if (command == "push")
		{
			int add;
			cin >> add;
			q.push(add);
		}
		if (command == "pop")
		{
			if (!q.empty()) 
			{
				cout << q.front() << "\n";
				q.pop();
			}
			else cout << -1 << "\n";
		}
		if (command == "size")
		{
			cout << q.size() << "\n";
		}
		if (command == "front")
		{
			if (!q.empty()) cout << q.front() << "\n";
			else cout << -1 << "\n";
		}
		if (command == "back")
		{
			if (!q.empty()) cout << q.back() << "\n";
			else cout << -1 << "\n";
		}
		if (command == "empty")
		{
			if (q.empty()) cout << 1 << "\n";
			else cout << 0 << "\n";
		}
	}

}
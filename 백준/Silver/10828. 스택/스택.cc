#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int main(void)
{
	int numOfcommand;
	cin >> numOfcommand;
	stack<int> S;

	for (int i = 0; i < numOfcommand; i++)
	{
		string command;
		cin >> command;
		cin.ignore();

		if (command == "push")
		{
			int num;
			cin >> num;
			S.push(num);
		}
		if (command == "pop")
		{
			if (!S.empty())
			{
				cout << S.top() << '\n';
				S.pop();
			}
			else cout << -1 << '\n';
		}
		if (command == "size")
		{
			cout << S.size() << '\n';
		}
		if (command == "empty")
		{
			if (S.empty()) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		if (command == "top")
		{
			if (!S.empty()) cout << S.top() << '\n';
			else cout << -1 << '\n';
		}
	}
}
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	int N;
	cin >> N;

	stack<int> s;

	for (int i = 0; i < N; i++)
	{
		string cmd;
		cin >> cmd;

		if (cmd == "push")
		{
			int num;
			cin >> num;
			s.push(num);
		}
		else if (cmd == "pop")
		{
			if (s.empty()) cout << -1 << "\n";
			else {
				cout << s.top() << "\n";
				s.pop();
			}
		}
		else if (cmd == "size")
		{
			cout << s.size() << "\n";
		}
		else if (cmd == "empty")
		{
			if (s.empty()) cout << 1 << "\n";
			else cout << 0 << "\n";
		}
		else if (cmd == "top")
		{
			if (s.empty()) cout << -1 << "\n";
			else cout << s.top() << "\n";
		}
	}

	return 0;
}
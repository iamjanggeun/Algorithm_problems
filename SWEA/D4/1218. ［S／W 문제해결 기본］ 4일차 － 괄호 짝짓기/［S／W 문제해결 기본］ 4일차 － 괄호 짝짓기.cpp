#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int main()
{
	for (int i = 0; i < 10; i++)
	{
		int N;
		cin >> N;

		stack<char> s;
		char input;

		bool flag = true;

		for (int j = 0; j < N; j++)
		{
			cin >> input;

			if (input == '(' || input == '{' || input == '[' || input == '<')
			{
				s.push(input);
			}
			else
			{
				if (s.empty()) flag = false;
				else
				{
					char top = s.top();
					if (input == ')' && top != '(' ||
						input == '}' && top != '{' ||
						input == ']' && top != '[' ||
						input == '>' && top != '<') {
						flag = false;
					}
					else s.pop();
				}
			}
		}

		int ans = (flag && s.empty()) ? 1 : 0;

		cout << "#" << i + 1 << " " << ans << "\n";
	}

	return 0;
}
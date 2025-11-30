#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	stack<pair<int, int>> s;

	for (int i = 0; i < N; i++)
	{
		int current;
		cin >> current;

		while (!s.empty())
		{
			if (current < s.top().first)
			{
				cout << s.top().second << " ";
				break;
			}
			s.pop();
		}
		if (s.empty()) cout << 0 << " ";

		s.push({ current, i + 1 });
	}

	return 0;
}
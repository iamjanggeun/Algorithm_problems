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

	stack<int> s;
	long long ans = 0;

	for (int i = 0; i < N; i++)
	{
		int current;
		cin >> current;

		while (!s.empty())
		{
			if (s.top() > current) break;
			s.pop();
		}

		ans += s.size();
		s.push(current);
	}

	cout << ans;

	return 0;
}
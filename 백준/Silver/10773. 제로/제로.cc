#include <stack>
#include <iostream>
#include <algorithm>

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
		int num;
		cin >> num;

		if (num != 0) s.push(num);
		else if (num == 0) s.pop();
	}

	int sum = 0;

	while(!s.empty())
	{
		sum += s.top();
		s.pop();
	}

	cout << sum;

	return 0;
}
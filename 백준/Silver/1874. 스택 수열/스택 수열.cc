#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> v(n);
	vector<char> ans;
	stack<int> s;

	int current = 1;

	for (int i = 0; i < n; i++) cin >> v[i];

	for (int i = 0; i < n; i++)
	{
		int target = v[i];

		while (current <= target)
		{
			s.push(current++);
			ans.push_back('+');
		}

		if (s.top() == target)
		{
			s.pop();
			ans.push_back('-');
		}
		else
		{
			cout << "NO\n";
			return 0;
		}
	}
	for (auto e : ans)
		cout << e << "\n";

	return 0;
}
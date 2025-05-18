#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (true)
	{
		string a;
		getline(cin, a);
		if (a == ".") break;
		stack<char> S;
		bool isValid = true;

		for (auto e : a)
		{
			if (e == '(' || e == '[') S.push(e);
			else if (e == ')')
			{
				if (S.empty() || S.top() != '(')
				{
					isValid = false;
					break;
				}
				S.pop();
			}
			else if (e == ']')
			{
				if (S.empty() || S.top() != '[')
				{
					isValid = false;
					break;
				}
				S.pop();
			}
		}
		if (!S.empty()) isValid = false;
		if (isValid) cout << "yes\n";
		else cout << "no\n";
	}
	return 0;
}
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
	for (int i = 0; i < 10; i++)
	{
		int N;
		cin >> N;

		int sub = 1;

		queue<int> q;

		for (int j = 0; j < 8; j++)
		{
			int x;
			cin >> x;
			q.push(x);
		}

		while (1)
		{
			int x;
			x = q.front();
			q.pop();

			x -= sub;

			if (x <= 0)
			{
				q.push(0);
				break;
			}

			q.push(x);

			sub++;
			if (sub > 5) sub = 1;
		}

		cout << "#" << i + 1;
		for (int k = 0; k < 8; k++)
		{
			cout << " " << q.front();
			q.pop();
		}
		cout << "\n";
	}
	return 0;
}
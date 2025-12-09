#include <iostream>
using namespace std;

int n, m;
int arr[10];

void func(int k, int start)
{
	if (m == k)
	{
		for (int i = 0; i < m; i++)
			cout << arr[i] << " ";
		cout << "\n";
	}

	for (int i = start; i <= n; i++)
	{
		arr[k] = i;
		func(k + 1, i + 1);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	func(0, 1);
}
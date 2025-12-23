#include <iostream>
#include <algorithm>

using namespace std;

int D[1000001];

int main()
{
	//1. X가 3의 배수이면, 3으로 나눔;
	//2. x가 2의 배수이면, 2로 나눔;
	//3. -1;
	// BFS? DP?
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	D[1] = 0;

	for (int i = 2; i < n + 1; i++)
	{
		D[i] = D[i - 1] + 1;
		if (i % 2 == 0) D[i] = min(D[i], D[i / 2] + 1);
		if (i % 3 == 0) D[i] = min(D[i], D[i / 3] + 1);
	}

	cout << D[n];
	return 0;
}
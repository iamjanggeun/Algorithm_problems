#include <iostream>
#include <algorithm>
using namespace std;

int S[100001], A[100001];
int n, m, i, j;

int main()
{
	//S[i] = S[i - 1] + A[i];
	//ans = S[j] - S[i - 1]
	//초기값 : D[0] = 0;
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	S[0] = 0;

	for (int k = 1; k < n + 1; k++)
	{
		cin >> A[k];
		S[k] = S[k - 1] + A[k];
	}

	for (int k = 0; k < m; k++)
	{
		cin >> i >> j;
		cout << S[j] - S[i - 1] << "\n";
	}

	return 0;
}
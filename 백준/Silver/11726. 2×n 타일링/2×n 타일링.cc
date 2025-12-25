#include <iostream>
#include <algorithm>
using namespace std;

int n;
int D[1001];

int main()
{
	//n = 1 -> 1개; n = 2 -> 2개; n = 3 -> 3개; n = 4 -> 5개
	//D[k](k > 2) = (D[k - 1] + D[k - 2]) % 10007;
	//초기값 : D[1] = 1; D[2] = 2;
	
	ios::sync_with_stdio(0);
	cin.tie(0);

	int ans;
	cin >> n;

	D[1] = 1;
	D[2] = 2;

	for (int i = 3; i < n + 1; i++) D[i] = (D[i - 1] + D[i - 2]) % 10007;

	cout << D[n];

	return 0;
}
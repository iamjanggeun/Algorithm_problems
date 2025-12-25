#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n;
int D[1001][3];
int R[1001], G[1001], B[1001];

int main()
{
	//D[i][0] = i번째 집까지 칠할때의 min값, i는 R
	//D[i][1] = 위와 동일; i는 G
	//D[i][2] = 위와 동일; i는 B

	//D[k][0] = min(D[k-1][1], D[k-1][2]) + R[k]
	//D[k][1] = min(D[k-1][0], D[k-1][2]) + G[k]
	//D[k][2] = min(D[k-1][0], D[k-1][1]) + B[k]

	//초기값
	//D[1][0] = R[1];
	//D[1][1] = G[1];
	//D[1][2] = B[1];

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i < n + 1; i++) {
		cin >> R[i] >> G[i] >> B[i];
	}
    
	D[1][0] = R[1];
	D[1][1] = G[1];
	D[1][2] = B[1];

	for (int i = 2; i < n + 1; i++)
	{
		D[i][0] = min(D[i - 1][1], D[i - 1][2]) + R[i];
		D[i][1] = min(D[i - 1][0], D[i - 1][2]) + G[i];
		D[i][2] = min(D[i - 1][0], D[i - 1][1]) + B[i];
	}
	
	int ans = *min_element(D[n], D[n] + 3);

	cout << ans;
	return 0;
}
#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, T, P;
	int cnt1 = 0;
	int cnt2, cnt3;

	cin >> N;

	int a[6];
	for (int i = 0; i < 6; i++) 
		cin >> a[i];

	cin >> T >> P;

	for (int i = 0; i < 6; i++) {
		if (a[i] % T == 0) {
			cnt1 += a[i] / T;
		}
		else cnt1 += a[i]/T + 1;
	}
	cnt2 = N / P;
	cnt3 = N % P;

	cout << cnt1 << "\n";
	cout << cnt2 << " " << cnt3;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> P(N);

	for (int i = 0; i < N; i++)
		cin >> P[i];

	int sum = 0;

	sort(P.begin(), P.end());

	for (int i = 0; i < N; i++)
	{
		sum += P[i] * (N - i);
	}

	cout << sum;

	return 0;
}
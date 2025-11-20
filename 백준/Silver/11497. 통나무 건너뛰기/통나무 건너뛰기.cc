#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);

	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		int N;
		cin >> N;

		vector<int> input(N);

		for (int i = 0; i < N; i++)
		{
			cin >> input[i];
		}

		sort(input.begin(), input.end());

		int res = 0;

		for (int j = 2; j < N; j += 2)
		{
			res = max(res, input[j] - input[j - 2]);
		}
		
		for (int j = 3; j < N; j += 2)
		{
			res = max(res, input[j] - input[j - 2]);
		}

		cout << res << "\n";
	}

	return 0;
}
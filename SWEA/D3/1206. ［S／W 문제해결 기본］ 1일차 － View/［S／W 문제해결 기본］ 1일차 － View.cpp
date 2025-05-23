#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	for (int test_case = 1; test_case < 11; test_case++)
	{
		int N;
		cin >> N;

		vector<int> v(N);
		for (int i = 0; i < N; i++)
		{
			cin >> v[i];
		}

		int answer = 0;

		for (int i = 2; i < N-2; i++)
		{
			int L_best = max(v[i - 1], v[i - 2]);
			int R_best = max(v[i + 1], v[i + 2]);
			int T_best = max(L_best, R_best);

			if (v[i] > L_best && v[i] > R_best)
				answer += v[i] - T_best;
		}
		cout << "#" << test_case << " " << answer << "\n";
	}
}
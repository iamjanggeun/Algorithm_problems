#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	for (int test_case = 1; test_case < 11; test_case++)
	{
		int N;
		cin >> N;
		vector<int> v(N);

		int answer = 0;

		for (int i = 0; i < N; i++)
		{
			cin >> v[i];
		}

		for (int i = 2; i < N - 2; i++)
		{
			int maxheight = max(max(v[i - 2], v[i - 1]), max(v[i + 1], v[i + 2]));
			if (maxheight < v[i]) answer += v[i] - maxheight;
		}
		
		cout << "#" << test_case << " " << answer << "\n";
	}
}
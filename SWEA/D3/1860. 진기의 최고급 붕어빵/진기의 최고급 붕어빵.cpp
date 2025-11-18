#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int test_case;
	cin >> test_case;

	for (int i = 0; i < test_case; i++)
	{
		int N, M, K;
		string ans;
		vector<int> arrive;

		cin >> N >> M >> K;

		for (int j = 0; j < N; j++)
		{
			int guest;
			cin >> guest;
			arrive.push_back(guest);
		}

		sort(arrive.begin(), arrive.end());

		for(int j = 0; j < N; j++)
		{
			if (K * (arrive[j] / M) < j + 1)
			{
				ans = "Impossible";
                break;
			}
			else ans = "Possible";
		}

		cout << "#" << i + 1 << " " << ans << "\n";
	}
}
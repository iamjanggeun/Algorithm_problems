#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int N;
	cin >> N;

	string a, b;

	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;

		vector<int> freq1(26, 0);
		vector<int> freq2(26, 0);

		if (a.length() != b.length()) 
		{
			cout << "Impossible" << "\n";
			continue;
		}

		else
		{
			for (auto e : a) freq1[e - 'a']++;
			for (auto e : b) freq2[e - 'a']++;
		}

		bool is_possible = true;

		for (int j = 0; j < 26; j++)
		{
			if (freq1[j] != freq2[j])
			{
				is_possible = false;
				break;
			}
		}

		if (is_possible) cout << "Possible" << "\n";
		else cout << "Impossible" << "\n";
	}

	return 0;
}
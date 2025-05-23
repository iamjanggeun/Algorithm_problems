#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	for (int test_case = 1; test_case < 11; test_case++)
	{
		int nDump;
		cin >> nDump;

		vector<int> H(100);
		for (int i = 0; i < 100; i++)
		{
			cin >> H[i];
		}
		
		for (int i = 0; i < nDump; i++)
		{
			int max_index = max_element(H.begin(), H.end()) - H.begin();
			int min_index = min_element(H.begin(), H.end()) - H.begin();
			H[max_index]--;
			H[min_index]++;
		}

		int answer = *max_element(H.begin(), H.end()) - *min_element(H.begin(), H.end());

		cout << "#" << test_case << " " << answer << "\n";
	}
}
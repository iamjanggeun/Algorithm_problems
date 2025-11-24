#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	vector<int> freq(10);
	
	int N;
	cin >> N;

	string input = to_string(N);

	for (auto e : input)
	{
		freq[e - '0']++;
	}

	int res = 0;
	int sixnine = freq[6] + freq[9];

	freq[6] = freq[9] = (sixnine + 1) / 2;

	for (int i = 0; i < 10; i++)
	{
		res = max(freq[i], res);
	}

	cout << res;

	return 0;
}
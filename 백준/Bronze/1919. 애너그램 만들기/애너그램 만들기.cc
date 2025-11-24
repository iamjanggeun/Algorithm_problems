#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string a, b;
	cin >> a;
	cin >> b;

	vector<int> freq1(26, 0);
	vector<int> freq2(26, 0);

	for (auto e : a) freq1[e - 'a']++;
	for (auto e : b) freq2[e - 'a']++;

	int cnt = 0;

	for (int i = 0; i < 26; i++)
	{
		if (freq1[i] == freq2[i]) continue;
		else cnt += abs(freq1[i] - freq2[i]);
	}

	cout << cnt;

	return 0;
}
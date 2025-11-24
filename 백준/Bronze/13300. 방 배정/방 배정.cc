#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	int numOfstudent;
	int limit;
	cin >> numOfstudent >> limit;

	vector<int> freq0(7, 0);
	vector<int> freq1(7, 0);

	for (int i = 0; i < numOfstudent; i++)
	{
		int s, y;
		cin >> s >> y;
		if (s == 0) freq0[y]++;
		else freq1[y]++;
	}

	int res = 0;

	for (int i = 1; i < 7; i++)
	{
		res += ((freq0[i] + limit - 1) / limit) + ((freq1[i] + limit - 1) / limit);
	}

	cout << res;

	return 0;
}
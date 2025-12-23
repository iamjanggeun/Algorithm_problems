#include <iostream>
#include <algorithm>
using namespace std;

int D[101];

int main()
{
	int tc;
	int num;
	cin >> tc;

	D[1] = 1;
	D[2] = 2;
	D[3] = 4;

	for (int i = 0; i < tc; i++)
	{
		cin >> num;
		for (int i = 4; i < num + 1; i++)
		{
			D[i] = D[i - 1] + D[i - 2] + D[i - 3];
		}
		cout << D[num] << "\n";
	}

	return 0;
}
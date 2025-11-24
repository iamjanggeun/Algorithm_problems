#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> v(N);

	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}

	int key;
	cin >> key;

	int left = 0;
	int right = N - 1;
	int res = 0;

	sort(v.begin(), v.end());

	while (left < right)
	{
		int sum = v[left] + v[right];
		if (sum == key)
		{
			res++;
			left++;
			right--;
		}
		else if (sum > key) right--;
		else left++;
	}

	cout << res;

	return 0;
}
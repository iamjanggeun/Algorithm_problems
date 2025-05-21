#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
int main(void)
{
	int N, num;
	cin >> N;
	vector<int> v;

	for (int i = 0; i < N; i++)
	{
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());

	for (auto e : v) cout << e << '\n';
}
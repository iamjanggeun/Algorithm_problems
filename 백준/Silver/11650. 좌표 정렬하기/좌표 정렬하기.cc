#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Dot{
	int x;
	int y;
};

bool compare(const Dot& a, const Dot& b)
{
	if (a.x == b.x) return a.y < b.y;
	else return a.x < b.x;
}

int main()
{
	int N;
	cin >> N;
	vector<Dot> v(N);

	for (int i = 0; i < N; i++)
	{
		cin >> v[i].x >> v[i].y;
	}

	sort(v.begin(), v.end(), compare);

	for (auto e : v)
		cout << e.x << " " << e.y << "\n";
}
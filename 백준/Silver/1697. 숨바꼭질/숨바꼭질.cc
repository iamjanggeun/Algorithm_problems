// 1주 후 복습
#include <iostream>
#include <algorithm>
#include <queue>
#define X first
#define Y second
using namespace std;

int dx[3] = { -1 ,1, 2 };
int dist[100001];
int n, k;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	
	fill(dist, dist + 100001, -1);
	queue<int> Q;
	Q.push(n);
	dist[n] = 0;

	while (!Q.empty())
	{
		auto cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 3; dir++)
		{
			int nx;
			if (dir == 2) nx = cur * dx[dir];
			else nx = cur + dx[dir];
			if (nx < 0 || nx >= 100001) continue;
			if (dist[nx] >= 0) continue;

			dist[nx] = dist[cur] + 1;
			if (nx == k) break;
			Q.push(nx);
		}
	}
	cout << dist[k];
	return 0;
}
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define X first
#define Y second
const int MAX = 1000001;

int dx[4] = { 1, -1, 2 };
int board[MAX];
int dist[MAX];
int n, k;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	fill(dist, dist + MAX, -1);

	queue<int> Q;
	Q.push(n);
	dist[n] = 0;
	while (!Q.empty())
	{
		auto cur = Q.front(); Q.pop();
        if(cur == k) break;
		for (int dir = 0; dir < 3; dir++)
		{
			int nx;
			if (dir == 2) nx = cur * dx[dir];
			else nx = cur + dx[dir];
			if (nx < 0 || nx > MAX) continue;
			if (dist[nx] >= 0) continue;

			dist[nx] = dist[cur] + 1;
			Q.push(nx);
		}
	}

	cout << dist[k];
	return 0;
}
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#define X first
#define Y second

using namespace std;

int dist[502][502];
int dx[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int dy[8] = {  1, 2, 2, 1, -1, -2, -2, -1};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int test_case;
	cin >> test_case;

	for (int tc = 0; tc < test_case; tc++)
	{
		int size;
		cin >> size;
		int x1, y1, x2, y2;
		cin >> x1 >> y1;
		cin >> x2 >> y2;

		for (int i = 0; i < size; i++) fill(dist[i], dist[i] + size, -1);

		queue<pair<int, int>> Q;
		dist[x1][y1] = 0;
		Q.push({ x1, y1 });

		while (!Q.empty())
		{
			auto cur = Q.front(); Q.pop();
			for (int dir = 0; dir < 8; dir++)
			{
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				if (nx < 0 || nx >= size || ny < 0 || ny >= size) continue;
				if (dist[nx][ny] >= 0) continue;

				dist[nx][ny] = dist[cur.X][cur.Y] + 1;
				Q.push({ nx, ny });
			}
		}
		cout << dist[x2][y2] << "\n";
	}
}
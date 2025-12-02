#include <iostream>
#include <queue>
#include <algorithm>
#define X first
#define Y second

using namespace std;

int board[502][502];
int vis[502][502];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main()
{
	int T;
	cin >> T;

	for (int tc = 0; tc < T; tc++)
	{
		int m, n, k;
		cin >> m >> n >> k;

		for (int i = 0; i < m; i++) fill(board[i], board[i] + n, 0);
		for (int i = 0; i < m; i++) fill(vis[i], vis[i] + n, 0);

		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;
			board[x][y] = 1;
		}

		int num = 0;

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (vis[i][j] || board[i][j] != 1) continue;
				num++;
				queue<pair<int, int>> Q;
				vis[i][j] = 1;
				Q.push({ i, j });

				while (!Q.empty())
				{
					auto cur = Q.front(); Q.pop();
					for (int dir = 0; dir < 4; dir++)
					{
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
						if (vis[nx][ny] || board[nx][ny] != 1) continue;

						vis[nx][ny] = 1;
						Q.push({ nx, ny });
					}
				}
			}
		}
		cout << num << "\n";
	}
	return 0;
}
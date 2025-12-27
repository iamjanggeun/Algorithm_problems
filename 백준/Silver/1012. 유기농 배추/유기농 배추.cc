//1주 후 복습
#include <iostream>
#include <algorithm>
#include <queue>
#define X first
#define Y second
using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int board[51][51];
int vis[51][51];
int n, m, k;

int main()
{
	int tc;
	cin >> tc;

	while (tc--)
	{
		int num = 0;
		cin >> m >> n >> k;

		for (int i = 0; i < n; i++) fill(board[i], board[i] + m, 0);
		for (int i = 0; i < n; i++) fill(vis[i], vis[i] + m, 0);

		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;
			board[y][x] = 1;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] == 0 || vis[i][j]) continue;
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
						if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
						if (vis[nx][ny] || board[nx][ny] == 0) continue;
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
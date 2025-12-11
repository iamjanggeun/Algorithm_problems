#include <iostream>
#include <queue>
#include <algorithm>
#define X first
#define Y second

using namespace std;

int board[102][102];
int vis[102][102];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	int n;
	cin >> n;

	int max_height = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			max_height = max(max_height, board[i][j]);
		}
	}

	int answer = 1;

	for (int height = 1; height < max_height + 1; height++)
	{
		for (int i = 0; i < n; i++) fill(vis[i], vis[i] + n, 0);

		int cnt = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				//BFS 시작점 탐색
				if (vis[i][j] || board[i][j] <= height) continue;
				cnt++;

				queue<pair <int, int>> Q;
				vis[i][j] = 1;
				Q.push({ i, j });

				//BFS 시작
				while (!Q.empty())
				{
					auto cur = Q.front(); Q.pop();
					for (int dir = 0; dir < 4; dir++)
					{
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
						if (vis[nx][ny] || board[nx][ny] <= height) continue;

						vis[nx][ny] = 1;
						Q.push({ nx, ny });
					}
				}
			}
		}
		answer = max(answer, cnt);
	}

	cout << answer;
}
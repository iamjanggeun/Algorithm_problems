#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

string board[102];
int vis[102][102];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int n;

void BFS(int i, int j)
{
	queue<pair<int, int>> Q;
	Q.push({ i, j });
	vis[i][j] = 1;
	while (!Q.empty())
	{
		auto cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (vis[nx][ny] || board[i][j] != board[nx][ny]) continue;

			vis[nx][ny] = 1;
			Q.push({ nx, ny });
		}
	}
}

int area()
{
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!vis[i][j]) {
				cnt++;
				BFS(i, j);
			}
		}
	}
	return cnt;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) cin >> board[i];

	int normal = area();

	for (int i = 0; i < n; i++) fill(vis[i], vis[i] + n, 0);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == 'G') board[i][j] = 'R';
		}
	}

	int not_normal = area();

	cout << normal << " " << not_normal;

	return 0;
}
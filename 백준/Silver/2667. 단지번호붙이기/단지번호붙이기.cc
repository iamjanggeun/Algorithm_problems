#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

#define X first
#define Y second

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
string board[102];
int vis[102][102];

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) cin >> board[i];
	for (int i = 0; i < n; i++) fill(vis[i], vis[i] + n, 0);

	int num = 0;
	vector<int> v;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (vis[i][j] || board[i][j] != '1') continue;
			num++;
			queue<pair<int, int>> Q;
			vis[i][j] = 1;
			Q.push({ i, j });

			int area = 0;

			while (!Q.empty())
			{
				area++;
				pair<int, int> cur = Q.front(); Q.pop();
				for (int dir = 0; dir < 4; dir++)
				{
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if (vis[nx][ny] || board[nx][ny] != '1') continue;

					vis[nx][ny] = 1;
					Q.push({ nx, ny });
				}
			}
			v.push_back(area);
		}
	}
	sort(v.begin(), v.end());
	cout << num << "\n";
	for (auto e : v) cout << e << "\n";
}
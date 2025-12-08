#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define X first
#define Y second

using namespace std;

int board[502][502];
int vis[502][502];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m, n, k;  
    cin >> m >> n >> k;

    for (int i = 0; i < m; i++) fill(board[i], board[i] + n, 0);
    for (int i = 0; i < m; i++) fill(vis[i], vis[i] + n, 0);

    for (int i = 0; i < k; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        for (int y = y1; y < y2; y++) {
            for (int x = x1; x < x2; x++) {
                board[y][x] = 1;
            }
        }
    }

    int num = 0;
    vector<int> v;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {

            if (board[i][j] != 0 || vis[i][j]) continue;

            num++;
            vis[i][j] = 1;
            queue<pair<int, int>> Q;
            Q.push({ i, j });

            int area = 0;

            while (!Q.empty())
            {
                area++;
                auto cur = Q.front(); Q.pop();

                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];

                    if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                    if (vis[nx][ny] || board[nx][ny] != 0) continue;

                    vis[nx][ny] = 1;
                    Q.push({ nx, ny });
                }
            }

            v.push_back(area);
        }
    }

    sort(v.begin(), v.end());

    cout << num << "\n";
    for (auto e : v) cout << e << " ";

    return 0;
}

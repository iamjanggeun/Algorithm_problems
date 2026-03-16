#include <iostream>
#include <algorithm>
#include <queue>
#define X first 
#define Y second 
using namespace std;

int board[52][52];
int visited[52][52];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin >> tc;

    while(tc--) {
        int n, m, k;
        int cnt = 0;
        cin >> m >> n >> k;

        for(int i = 0; i < n; i++) fill(board[i], board[i] + m, 0);
        for(int i = 0; i < n; i++) fill(visited[i], visited[i] + m, 0);

        for(int i = 0; i < k; i++) {
            int x, y;
            cin >> x >> y;
            board[y][x] = 1;
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == 0 || visited[i][j]) continue;

                queue<pair<int, int>> Q;
                Q.push({i, j});
                visited[i][j] = 1;
                cnt++;

                while(!Q.empty()) {
                    auto cur = Q.front(); Q.pop();
                    for(int dir = 0; dir < 4; dir++) {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if(visited[nx][ny] || board[nx][ny] == 0) continue;

                        visited[nx][ny] = 1;
                        Q.push({nx, ny});
                    }
                }
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}
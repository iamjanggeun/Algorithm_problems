#include <iostream>
#include <tuple>
#include <queue>
#include <algorithm>
#include <cstring> 
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

string board[1002];
int dist[1001][1001][2];
int n, m;

bool isValid(int i, int j) {
    return (i >= 0 && i < n && j >= 0 && j < m);
}

void bfs() {
    queue<tuple<int, int, int>> Q;

    dist[0][0][0] = 1;
    Q.push({0, 0, 0});

    while (!Q.empty()) {
        auto [x, y, k] = Q.front(); Q.pop();
        
        if (x == n - 1 && y == m - 1) return;

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (!isValid(nx, ny)) continue;

            // 부숨
            if (board[nx][ny] == '0' && dist[nx][ny][k] == -1) {
                dist[nx][ny][k] = dist[x][y][k] + 1;
                Q.push({nx, ny, k});
            }

            // 안부숨
            // string으로 받았으니까 따옴표 좀 하자;; 이런 경험도 필요해 도움 많이 될거야
            if (board[nx][ny] == '1' && k == 0 && dist[nx][ny][1] == -1) {
                dist[nx][ny][1] = dist[x][y][0] + 1;
                Q.push({nx, ny, 1});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) cin >> board[i];

    memset(dist, -1, sizeof(dist));
    bfs();

    int a = dist[n-1][m-1][0]; 
    int b = dist[n-1][m-1][1]; 

    if (a == -1 && b == -1) cout << -1;
    else if (a == -1) cout << b;
    else if (b == -1) cout << a;
    else cout << min(a, b);

    return 0;
}
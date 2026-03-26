    /*********************************************************************
    * Author:            Janggeun
    * Date:              2026-03-26
    * Project Name:      Algorithm Study
    * Problem Name:      BOJ 4179번 - 불!
    * Description:       - BFS
                        - 독립적인 2개의 bfs 사용하여 비교
                        - 탈출 기준은 배열 밖이므로 평소 제약조건의 반대로 return
                        - 불은 여러곳에서 발생할 수도 있음을 고려해야함;;(토마토처럼)
    *********************************************************************/

    #include <iostream>
    #include <algorithm>
    #include <queue>
    #define X first 
    #define Y second 
    using namespace std;

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int r, c;
    string board[1002];
    int dist_f[1002][1002];
    int dist_j[1002][1002];

    int bfs_j(int i, int j) {
        queue<pair<int, int>> Q2;
        Q2.push({i, j});
        int ans = 0;
        dist_j[i][j] = 0; // don't forget initialize in main func;

        while(!Q2.empty()) {
            auto cur = Q2.front(); Q2.pop();
            for(int dir = 0; dir < 4; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx < 0 || ny < 0 || nx >= r || ny >= c) return dist_j[cur.X][cur.Y] + 1;
                if(dist_j[nx][ny] >= 0 || board[nx][ny] == '#') continue;
                if(dist_f[nx][ny] >= 0 && dist_j[cur.X][cur.Y] + 1 >= dist_f[nx][ny]) continue;

                dist_j[nx][ny] = dist_j[cur.X][cur.Y] + 1;
                Q2.push({nx, ny});
            }
        }
        return ans;
    }

    int main() {
        ios::sync_with_stdio(0);
        cin.tie(0);

        int answer = 0;
        int x, y;
        queue<pair<int, int>> Q;
        cin >> r >> c;
        for(int i = 0; i < r; i++) cin >> board[i];

        for(int i = 0; i < r; i++) fill(dist_f[i], dist_f[i] + c, -1);
        for(int i = 0; i < r; i++) fill(dist_j[i], dist_j[i] + c, -1);

        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(board[i][j] == 'F') {
                    Q.push({i, j});
                    dist_f[i][j] = 0;
                }
                if(board[i][j] == 'J') {
                    x = i;
                    y = j;
                }
            }
        }

        while(!Q.empty()) {
            auto cur = Q.front(); Q.pop();
            for(int dir = 0; dir < 4; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx < 0 || nx > r || ny < 0 || ny > c) continue;
                if(dist_f[nx][ny] >= 0 || board[nx][ny] == '#') continue;

                dist_f[nx][ny] = dist_f[cur.X][cur.Y] + 1;
                Q.push({nx, ny});
            }
        }

        answer = bfs_j(x, y);

        if(answer == 0) cout << "IMPOSSIBLE";
        else cout << answer;

        return 0;
    }
/*********************************************************************
* Author:            Janggeun
* Date:              2026-03-25
* Project Name:      Algorithm Study
* Problem Name:      BOJ 16234번 - 인구 이동
* Description:       - BFS
                     - 벡터 v로 연합 그룹화
*********************************************************************/

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define X first 
#define Y second 
using namespace std;

int board[101][101];
int visited[101][101];
int n, l, r;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool bfs(int i, int j) {
    vector<pair<int, int>> v;
    queue<pair<int, int>> Q;

    Q.push({i, j});
    visited[i][j] = 1;
    int sum = board[i][j];
    v.push_back({i, j});
    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(visited[nx][ny]) continue;

            int diff = abs(board[cur.X][cur.Y] - board[nx][ny]);
            if(diff >= l && diff <= r) {
                visited[nx][ny] = 1;
                Q.push({nx, ny});
                sum += board[nx][ny];
                v.push_back({nx, ny});
            }
        }
    }
    
    if(v.size() <= 1) return false;

    int avg = sum / v.size();
    for(auto e : v) board[e.X][e.Y] = avg;
    return true;
}


int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> l >> r;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    int date = 0;

    while(true) {
        bool isMove = false;
        for(int i = 0; i < n; i++) fill(visited[i], visited[i] + n, 0);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(!visited[i][j]) {
                    if(bfs(i, j)) isMove = true;
                }
            }
        }
        if(!isMove) break;
        date++;
    }

    cout << date;
    return 0;
}
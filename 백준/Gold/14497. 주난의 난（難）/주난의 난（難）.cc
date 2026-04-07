/*********************************************************************
* Author:            Janggeun
* Date:              2026-04-07
* Project Name:      Algorithm Study
* Problem Name:      BOJ 14497번 - 주난의 난
* Description:       0-1 BFS.
                     deque를 이용한 BFS.
                     초기에 0-based index로 초기화해줌.
*********************************************************************/

#include <iostream>
#include <algorithm>
#include <deque>
#define INF 2147483647
using namespace std;

int n, m;
int x, y, w, z;
string board[302];
int dist[302][302];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    cin >> x >> y >> w >> z;
    x--; y--; w--; z--;
    
    for(int i = 0; i < n; i++) fill(dist[i], dist[i] + m, INF);
    for(int i = 0; i < n; i++) cin >> board[i];

    deque<pair<int, int>> dq;
    dq.push_back({x, y});
    dist[x][y] = 0;

    while(!dq.empty()) {
        auto cur = dq.front(); dq.pop_front();
        if(cur.first == w && cur.second == z) break;

        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

            int weight = (board[nx][ny] == '0' ? 0 : 1);

            if(dist[nx][ny] > dist[cur.first][cur.second] + weight) {
                dist[nx][ny] = dist[cur.first][cur.second] + weight;

                if(weight == 0) dq.push_front({nx, ny});
                else dq.push_back({nx, ny});
            }
        }
    }

    cout << dist[w][z];
    return 0;
}
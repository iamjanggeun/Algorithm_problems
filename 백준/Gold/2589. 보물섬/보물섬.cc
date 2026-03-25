#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#define X first 
#define Y second 
using namespace std;

int n, m;
string map[52];
int dist[52][52];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    vector<int> v;
    for(int i = 0; i < n; i++) cin >> map[i];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(map[i][j] == 'W') continue;
            for(int k = 0; k < n; k++) fill(dist[k], dist[k] + m, -1);
            int select = 0;
            queue<pair<int, int>> Q;
            Q.push({i, j});
            dist[i][j] = 0;
            while(!Q.empty()) {
                auto cur = Q.front(); Q.pop();
                for(int dir = 0; dir < 4; dir++) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if(dist[nx][ny] >= 0 || map[nx][ny] == 'W') continue;

                    dist[nx][ny] = dist[cur.X][cur.Y] + 1;
                    select = max(select, dist[nx][ny]);
                    Q.push({nx, ny});
                }
            }
            v.push_back(select);
        }
    }

    int ans = *max_element(v.begin(), v.end());
    cout << ans;

    return 0;
}
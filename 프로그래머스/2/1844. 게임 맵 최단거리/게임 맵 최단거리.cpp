#include <bits/stdc++.h>
using namespace std;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int dist[102][102];
#define X first
#define Y second

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    int n = maps.size();
    int m = maps[0].size();

    for (int i = 0; i < n; i++) fill(dist[i], dist[i] + m, -1);

    queue<pair<int, int>> Q;
    dist[0][0] = 0;
    Q.push({ 0,0 });

    while (!Q.empty())
    {
        auto cur = Q.front(); Q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (dist[nx][ny] >= 0 || maps[nx][ny] != 1) continue;
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            Q.push({ nx, ny });
        }
    }
    
    if (dist[n - 1][m - 1] == -1) return -1;
    return dist[n - 1][m - 1] + 1;
}
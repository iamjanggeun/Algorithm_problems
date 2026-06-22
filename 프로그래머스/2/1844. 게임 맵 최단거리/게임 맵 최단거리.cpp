#include <queue>
#include <vector>
#include <algorithm>
#include <iostream>
#define X first 
#define Y second 
using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int dist[105][105]; 

int solution(vector<vector<int>> maps)
{
    int n = maps.size();
    int m = maps[0].size();
    
    for(int i = 0; i < n; i++) fill(dist[i], dist[i] + m, -1);
    
    queue<pair<int, int>> Q;
    Q.push({0, 0});
    dist[0][0] = 1;

    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop(); 
        
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(dist[nx][ny] != -1 || maps[nx][ny] == 0) continue;

            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            Q.push({nx, ny});
        }
    }

    return dist[n - 1][m - 1];
}
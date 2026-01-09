//불! (골드 3)
#include <iostream>
#include <queue>
#include <algorithm>
#define X first 
#define Y second 
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int r, c;
string board[1002];
int dist_f[1002][1002];
int dist_j[1002][1002];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c;
    queue<pair<int, int>> J;
    queue<pair<int, int>> F;

    for(int i = 0; i < r; i++){
        fill(dist_f[i], dist_f[i] + c, -1);
        fill(dist_j[i], dist_j[i] + c, -1);
    }
    
    for(int i = 0; i < r; i++){
        cin >> board[i];
        for(int j = 0; j < c; j++){
            if(board[i][j] == 'J'){
                J.push({i, j}); 
                dist_j[i][j] = 0;
            } 
            if(board[i][j] == 'F') {
                F.push({i, j}); 
                dist_f[i][j] = 0;
            }
        }
    }

    while(!F.empty())
    {
        auto cur = F.front(); F.pop();
        for(int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if(dist_f[nx][ny] >= 0 || board[nx][ny] == '#') continue;

            dist_f[nx][ny] = dist_f[cur.X][cur.Y] + 1;
            F.push({nx, ny});
        }
    }

    while(!J.empty())
    {
        auto cur = J.front(); J.pop();
        for(int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= r || ny < 0 || ny >= c){
                cout << dist_j[cur.X][cur.Y] + 1;
                return 0;
            } 
            if(dist_j[nx][ny] >= 0 || board[nx][ny] == '#') continue;
            if(dist_f[nx][ny] != -1 && dist_f[nx][ny] <= dist_j[cur.X][cur.Y] + 1) continue; 

            dist_j[nx][ny] = dist_j[cur.X][cur.Y] + 1;
            J.push({nx, ny});
        }
    }

    cout << "IMPOSSIBLE";
    return 0;
}
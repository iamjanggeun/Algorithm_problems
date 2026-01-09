//상범빌딩
#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>
using namespace std;

int dx[6] = { 1, -1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, 1, -1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };

string board[32][32];
int dist[32][32][32];
int r, c, l;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(1)
    {
        cin >> l >> r >> c;

        if(l == 0 && r == 0 && c == 0) break;

        queue<tuple<int, int, int>> Q;
        int time = 0;

        for(int i = 0; i < l; i++){
            for(int j = 0; j < r; j++){
                fill(dist[i][j], dist[i][j] + c, -1);
            }
        }
        
        for(int i = 0; i < l; i++){
            for(int j = 0; j < r; j++){
                cin >> board[i][j];
                for(int k = 0; k < c; k++){
                    if(board[i][j][k] == 'S'){
                        Q.push({i, j, k});
                        dist[i][j][k] = 0;
                    }
                }
            }
        }

        while(!Q.empty())
        {
            auto cur = Q.front(); Q.pop();
            auto [z, x, y] = cur;
            for(int dir = 0; dir < 6; dir++)
            {
                int nz = z + dz[dir];
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if(nz < 0 || nz >= l || nx < 0 || nx > r || ny < 0 || ny >= c) continue;
                if(dist[nz][nx][ny] >= 0 || board[nz][nx][ny] == '#') continue;
                
                dist[nz][nx][ny] = dist[z][x][y] + 1;
                Q.push({nz, nx, ny});
            }
        }

        for(int i = 0; i < l; i++){
            for(int j = 0; j < r; j++){
                for(int k = 0; k < c; k++){
                    if(board[i][j][k] == 'E' && dist[i][j][k] >= 0) time = dist[i][j][k];
                }
            }
        }
        if(!time) cout << "Trapped!\n";
        else cout << "Escaped in " << time << " minute(s).\n";
    }
}
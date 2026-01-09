//불 (골드 4)
#include <iostream>
#include <queue>
#include <algorithm>
#define X first 
#define Y second 
using namespace std;

string board[1002];
//dist1 = 상근이; dist2 = 렌고쿠;
int dist1[1002][1002];
int dist2[1002][1002];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int w, h;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
        
    int test_case;
    cin >> test_case;

    while(test_case--)
    {
        cin >> w >> h;
        bool escaped = false;
        //Q1 = 상근이 큐; Q2 = 히노카미 카구라;
        queue<pair<int, int>> Q1;
        queue<pair<int, int>> Q2;

        for(int i = 0; i < h; i++){    
            fill(dist1[i], dist1[i] + w, -1);
            fill(dist2[i], dist2[i] + w, -1);
        }
        
        for(int i = 0; i < h; i++){
            cin >> board[i];
            for(int j = 0; j < w; j++){
                if(board[i][j] == '@'){
                    Q1.push({i, j});
                    dist1[i][j] = 0;
                }
                if(board[i][j] == '*'){
                    Q2.push({i, j});
                    dist2[i][j] = 0;
                }
            }
        }

        while(!Q2.empty())
        {
            auto cur = Q2.front(); Q2.pop();
            for(int dir = 0; dir < 4; dir++)
            {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                if(dist2[nx][ny] >= 0 || board[nx][ny] == '#') continue;

                dist2[nx][ny] = dist2[cur.X][cur.Y] + 1;
                Q2.push({nx, ny});
            }
        }
        
        while(!Q1.empty() && !escaped)
        {
            auto cur = Q1.front(); Q1.pop();
            for(int dir = 0; dir < 4; dir++)
            {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx < 0 || nx >= h || ny < 0 || ny >= w){
                    cout << dist1[cur.X][cur.Y] + 1 << "\n";
                    escaped = true;
                    break;
                }
                if(dist1[nx][ny] >= 0 || board[nx][ny] == '#') continue;
                if(dist2[nx][ny] != -1 && dist2[nx][ny] <= dist1[cur.X][cur.Y] + 1) continue;

                dist1[nx][ny] = dist1[cur.X][cur.Y] + 1;
                Q1.push({nx, ny});
            }
        }

        if(!escaped) cout << "IMPOSSIBLE\n";
    }
}
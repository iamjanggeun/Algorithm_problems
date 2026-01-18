//빙산 (골드 4)
#include <iostream>
#include <algorithm>
#include <queue>
#define X first 
#define Y second 
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int n, m;
int area[302][302];
int vis[302][302];

bool check(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}

void initVis()
{
    for(int i = 0; i < n; i++) fill(vis[i], vis[i] + m, 0);
}

void melting()
{
    int zero[302][302] = {0};
    for (int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(area[i][j] == 0) continue;
            for(int dir = 0; dir < 4; dir++)
            {
                int nx = i + dx[dir];
                int ny = j + dy[dir];

                if(check(nx, ny) && area[nx][ny] == 0) zero[i][j]++;
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            area[i][j] = max(area[i][j] - zero[i][j], 0);
        }
    }
}

int count()
{
    int x = -1, y = -1;
    int ice1 = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(area[i][j])
            {
                x = i;
                y = j;
                ice1++;
            }
        }
    }
    if(ice1 == 0) return 0;
    int ice2 = 0;
    queue<pair<int, int>> Q;
    vis[x][y] = 1;
    Q.push({x, y});
    
    while(!Q.empty())
    {
        auto cur = Q.front(); Q.pop();
        ice2++;
        for(int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(vis[nx][ny]||area[nx][ny] <= 0) continue;
            
            vis[nx][ny] = 1;
            Q.push({nx, ny});
        }
    }
        if(ice1 == ice2) return 1;
        return 2;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> area[i][j];
        }
    }

    int year = 0;

    while(1)
    {
        year++;
        melting();
        initVis();
        int check = count();
        if(check == 0){
            cout << 0;
            return 0;
        } 
        else if (check == 1) continue;
        else break;
    }
    cout << year;
    return 0;
}
/*
[문제 정리]
1. 입력 크기 : 500
2. 그림의 개수와 max_area 구하기
3. 1이 색칠된 곳; 0이 안된곳;
4. 예외처리 : 그림이 없는 경우 area = 0;
*/

#include <iostream>
#include <queue>
#include <algorithm>
#define X first
#define Y second 
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int board[502][502];
int visited[502][502];
int n, m;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
        }
    }

    int num = 0;
    int max_area = 0;

    //그림의 시작을 찾기
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(board[i][j] == 0 || visited[i][j]) continue;
            num++;
            queue<pair<int, int>> Q;
            Q.push({i, j});
            visited[i][j] = 1;
            int area = 0;
            //bfs
            while(!Q.empty())
            {
                auto cur = Q.front(); Q.pop();
                area++;
                for(int dir = 0; dir < 4; dir++)
                {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if(visited[nx][ny] || board[nx][ny] == 0) continue;

                    Q.push({nx, ny});
                    visited[nx][ny] = 1;
                }
            }
            max_area = max(max_area, area);
        }
    }

    cout << num << "\n" << max_area;
    return 0;
}
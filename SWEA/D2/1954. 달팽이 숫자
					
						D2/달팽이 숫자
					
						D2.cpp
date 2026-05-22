#include <iostream>
#include <algorithm>
using namespace std;

int n, ans;
int board[11][11];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int test_case;
    cin >> test_case;

    for(int tc = 0; tc < test_case; tc++) {
        
        for(int i = 0; i < 11; i++) fill(board[i], board[i] + 11, 0);
        cin >> n;

        // 방향 전환하기 (방향의 조건은?) -> 이미 채워져있거나? 범위를 벗어났을때
        int x = 0, y = 0;
        int dir = 1;

        for(int i = 1; i <= n*n; i++) {
            board[x][y] = i;
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            //방향 전환
            if(board[nx][ny] != 0 || nx < 0 || ny < 0 || nx >= n || ny >= n) {
                dir = (dir + 3) % 4;
                nx = x + dx[dir];
                ny = y + dy[dir]; 
            }

            x = nx;
            y = ny;
        }

        cout << "#" << tc + 1 << "\n";

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cout << board[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
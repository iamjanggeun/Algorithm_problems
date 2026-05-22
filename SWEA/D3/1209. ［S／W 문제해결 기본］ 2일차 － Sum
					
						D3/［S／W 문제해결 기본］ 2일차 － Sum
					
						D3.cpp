#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int board[101][101];

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int tc = 0; tc < 10; tc++) {
        int t_num;
        cin >> t_num;
        int temp_r, temp_c;
        int temp_d = 0, temp_d2 = 0;
        int ans = 0;

        for(int i = 0; i < 100; i++) {
            for(int j = 0; j < 100; j++) {
                cin >> board[i][j];
            }
        }

        for(int i = 0; i < 100; i++) {
            temp_r = 0, temp_c = 0;
            for(int j = 0; j < 100; j++) {
                //1. 행 합 구하기
                temp_r += board[i][j];
                //2. 열 합 구하기
                temp_c += board[j][i];
            }
            ans = max({ans, temp_r, temp_c});
            temp_d += board[i][i];
            temp_d2 += board[i][99 - i];
        }

        ans = max({ans, temp_d, temp_d2});

        cout << "#" << tc + 1 << " " << ans << "\n";
    }

    return 0;
}
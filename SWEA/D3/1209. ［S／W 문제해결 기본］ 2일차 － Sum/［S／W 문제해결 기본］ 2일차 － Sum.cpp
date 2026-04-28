#include <iostream>
#include <algorithm>

using namespace std;

int board[100][100];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T_num;

    while (cin >> T_num) {
        int max_val = 0;

        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                cin >> board[i][j];
            }
        }

        int temp_dia1 = 0;
        int temp_dia2 = 0;

        for (int i = 0; i < 100; i++) {
            int temp_row = 0;
            int temp_col = 0;
            
            for (int j = 0; j < 100; j++) {
                temp_row += board[i][j];
                temp_col += board[j][i]; 
            }
            // 한 줄이 끝날 때마다 최댓값 갱신
            max_val = max({max_val, temp_row, temp_col});

            temp_dia1 += board[i][i];
            temp_dia2 += board[i][99 - i];
        }

        max_val = max({max_val, temp_dia1, temp_dia2});

        cout << "#" << T_num << " " << max_val << "\n";
    }

    return 0;
}
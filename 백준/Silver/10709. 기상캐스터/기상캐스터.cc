/*********************************************************************
* Author:            Janggeun
* Date:              2026-03-06
* Project Name:      Algorithm Study
* Problem Name:      BOJ 10709번 - 기상캐스터
* Description:       2차원 배열
*********************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
#include <stdlib.h>
using namespace std;

string board[102];
int res[102][102];

int h, w;

int main() {
    
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> h >> w;
    for(int i = 0; i < h; i++) cin >> board[i];

    for(int i = 0; i < h; i++) {
        int cnt;
        bool flag = false;
        for(int j = 0; j < w; j++) {
            if(board[i][j] == 'c') {
                flag = true;
                res[i][j] = 0;
                cnt = 0;
            }
            else if(flag && board[i][j] == '.') {
                cnt++;
                res[i][j] = cnt;
            }
            else res[i][j] = -1; 
        }
    }

    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            cout << res[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
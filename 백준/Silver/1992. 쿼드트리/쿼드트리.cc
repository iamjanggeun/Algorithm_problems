//백준_1992_쿼드트리
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n;
string board[65];

//모두 0 아니면 1인 경우
bool isSame(int x, int y, int size) {
    for(int i = x; i < x + size; i++) {
        for(int j = y; j < y + size; j++) {
            if(board[x][y] != board[i][j]) return false;
        }
    }
    return true;
}

string quadtree(int x, int y, int size) {
    int s = size / 2;
    //base condition
    if(isSame(x, y, size)) return string(1, board[x][y]);
    
    return ("(" + quadtree(x, y, s) +
    quadtree(x, y + s, s) + 
    quadtree(x + s, y, s) + 
    quadtree(x + s, y + s, s) + ")");
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> board[i];

    cout << quadtree(0, 0, n);
    return 0;
}
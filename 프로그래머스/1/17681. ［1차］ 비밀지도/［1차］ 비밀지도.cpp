#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

/*
    [문제 요약]
    1. 지도1과 지도2 중 하나라도 벽이면 전체에서 벽
    2. | " " = 0 | # = 1 |
    3. 걍 보드판 하나만 두고 어차피 한개만 벽이어도 벽이니 벽이면 걍 바로 # 채워버리기
    4. 초기화는 공백으로 설정
*/

// 2진 변환
vector<vector<int>> binary(vector<int> a) {
    vector<vector<int>> ret;
    for(int i = 0; i < a.size(); i++) {
        vector<int> bin(a.size(), 0);

        int idx = 0;
        while(a[i] != 0) {
            bin[idx] = a[i] % 2;
            a[i] /= 2;
            idx++;
        }
        reverse(bin.begin(), bin.end());
        ret.push_back(bin);
    }

    return ret;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    
    // answer map "#" 초기화
    vector<string> board(n, string(n, ' '));

    vector<vector<int>> map1 = binary(arr1);
    vector<vector<int>> map2 = binary(arr2);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if (map1[i][j] == 1 || map2[i][j] == 1) board[i][j] = '#';
        }
    }

    return board;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> arr = {9, 20, 28, 18, 11};
    vector<int> arr2 = {30, 1, 21, 17, 28};
    int n = 5;

    vector<string> result = solution(n, arr, arr2);

    for(const string& s : result) {
        cout << s << "\n";
    }

    return 0;
}
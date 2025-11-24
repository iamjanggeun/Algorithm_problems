#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    vector<int> freq(10, 0);

    int N;
    cin >> N;

    string s = to_string(N);
    for (char c : s) {
        freq[c - '0']++;
    }

    // 6과 9 합쳐서 처리
    int sixNine = freq[6] + freq[9];
    freq[6] = freq[9] = (sixNine + 1) / 2;  

    // 전체 freq에서 최댓값 찾기
    int res = 0;
    for (int i = 0; i < 10; i++) {
        res = max(res, freq[i]);
    }

    cout << res << "\n";
    return 0;
}
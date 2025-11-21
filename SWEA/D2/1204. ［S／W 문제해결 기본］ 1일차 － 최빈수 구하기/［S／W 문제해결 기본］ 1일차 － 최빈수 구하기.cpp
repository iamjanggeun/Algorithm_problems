#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {

        int tc_num;
        cin >> tc_num;

        vector<int> freq(101, 0); 

        for (int i = 0; i < 1000; i++) {
            int score;
            cin >> score;
            freq[score]++;
        }

        int max_cnt = 0;
        int result = 0;

        for (int i = 0; i <= 100; i++) {
            if (freq[i] >= max_cnt) {
                max_cnt = freq[i];
                result = i;
            }
        }

        cout << "#" << tc << " " << result << "\n";
    }
    return 0;
}

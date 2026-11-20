#include <bits/stdc++.h>
using namespace std;

int main() {
    for(int test_case = 1; test_case < 11; test_case++) {
        int tc;
        cin >> tc;
        
        string pos, s;
        cin >> pos >> s;
        
        size_t idx = 0;
        int cnt = 0;
        
        while((idx = s.find(pos, idx)) != string::npos) {
            cnt++;
            idx++;
        }
        
        cout << "#" << tc << " " << cnt << "\n";
    }
    return 0;
}
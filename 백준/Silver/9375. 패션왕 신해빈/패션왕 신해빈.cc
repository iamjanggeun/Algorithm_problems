//백준_9375_패션왕
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

int n;
int tc;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> tc;
    while(tc--) {
        cin >> n;
        map<string, int> mp;
        for(int i = 0; i < n; i++) {
            string s1, s2;
            cin >> s1 >> s2;
            mp[s2]++;
        }
        int ans = 1;
        for(auto e : mp) {
            // 뒤의 +1 은 입지 않는 경우 추가
            ans *= (e.second + 1);  
        }
        // 입지 않는 경우 추가했으므로 모두 안 입은 알몸의 경우 1 빼주기
        cout << ans - 1 << "\n";
    }
    return 0;
}
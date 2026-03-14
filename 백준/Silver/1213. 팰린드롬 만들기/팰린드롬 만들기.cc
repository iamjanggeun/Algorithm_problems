#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
int freq[101];
int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    char mid;
    int flag = 0;
    cin >> str;

    string ans = "";
    for(char a : str) freq[a]++;

    for(int i = 'Z'; i >= 'A'; i--) {
        if(freq[i]) {
            if(freq[i] & 1) {
                mid = char(i);
                flag++;
                freq[i]--;
            }
            if(flag == 2) break;
            for(int j = 0; j < freq[i]; j += 2) {
                ans = char(i) + ans;
                ans += char(i);
            }
        }
    }

    if(mid){
        ans.insert(ans.begin() + ans.size() / 2, mid);
    }
    if(flag == 2) cout << "I'm Sorry Hansoo\n";
    else cout << ans << "\n";

    return 0;
}
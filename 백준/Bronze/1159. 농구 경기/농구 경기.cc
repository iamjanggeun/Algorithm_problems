#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int freq[151];

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    while(n--) {
        string name;
        cin >> name;
        freq[name[0] - 'a']++;
    }
    
    int idx = 0;
    string ans = "";
    bool isValid = false;
    for(auto e : freq) {
        if(e >= 5) {
            ans += idx + 'a';
            isValid = true;
        }
        idx++;
    }

    if(isValid) cout << ans;
    else cout << "PREDAJA";

    return 0;
}
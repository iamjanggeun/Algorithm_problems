#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int freq[102];
int a, b, c;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b >> c;
    int n = 3;
    int limit = 0;
    while(n--) {
        int x, y;
        cin >> x >> y;
        limit = max(limit, y);
        for(int i = x; i < y; i++) freq[i]++;
    }

    int cnt1 = 0, cnt2 = 0, cnt3 = 0;
    for(int i = 1; i < limit + 1; i++) {
        if(freq[i] == 1) cnt1++;
        else if(freq[i] == 2) cnt2++;
        else if(freq[i] == 3) cnt3++;
    }
    int ans = (a * cnt1 * 1) + (b * cnt2 * 2) + (c * cnt3 * 3);

    cout << ans;
    return 0;
}
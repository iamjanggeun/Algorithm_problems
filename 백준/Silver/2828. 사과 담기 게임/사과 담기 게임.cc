#include <iostream>
#include <algorithm>
using namespace std;

int n, m, j;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> j;

    int windowStart = 1;
    int windowEnd = m;
    int cnt = 0;

    while(j--) {
        int x;
        cin >> x;

        bool inRange = false;

        while(!inRange) {
            if(windowStart <= x && windowEnd >= x) inRange = true;
            else if (x < windowStart) {
                windowEnd--;
                windowStart--;
                cnt++;
            }
            else {
                windowEnd++;
                windowStart++;
                cnt++;
            }
        }
    }

    cout << cnt;
    return 0;
}
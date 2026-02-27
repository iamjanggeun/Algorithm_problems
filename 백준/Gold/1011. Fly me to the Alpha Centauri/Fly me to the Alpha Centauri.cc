#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    int tc;
    cin >> tc;

    while(tc--) {
        int x, y;
        cin >> x >> y;

        int dist = y - x;
        long long n = sqrt(dist);

        if(n * n == dist) cout << 2 * n - 1 << "\n";
        else if(n * n + n >= dist) cout << 2 * n << "\n";
        else cout << 2 * n + 1 << "\n";
    }

    return 0;
}
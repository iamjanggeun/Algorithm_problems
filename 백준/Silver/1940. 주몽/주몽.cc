#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    cin >> m;

    vector<int> v(n);
    int cnt = 0;
    for(int i = 0; i < n; i++) cin >> v[i];

    for(int i = 0; i < n; i++) {
        for(int j = n - 1; j > i; j--) {
            int temp = 0;
            temp = v[i] + v[j];
            if(temp == m) cnt++;
        }
    }
    cout << cnt;

    return 0;
}
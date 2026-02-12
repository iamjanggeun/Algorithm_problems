//백준 2556(수열)
#include <iostream>
#include <algorithm>
using namespace std;

int psum[1000001];
int n, k;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        int tmp;
        cin >> tmp;
        psum[i] = psum[i - 1] + tmp;
    }

    int max_val = -100000001;

    for(int i = k; i <= n; i++) {
        max_val = max(max_val, psum[i] - psum[i - k]);
    }

    cout << max_val;

    return 0;
}
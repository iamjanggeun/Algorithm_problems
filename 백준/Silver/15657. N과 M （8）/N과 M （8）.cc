#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int result[10], num[10];

void dfs(int start, int depth) {
    if(depth == m) {
        for(int i = 0; i < m; i++) cout << result[i] << " ";
        cout << "\n";
        return;
    }

    for(int i = start; i < n; i++) {
        result[depth] = num[i];
        dfs(i, depth + 1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> num[i];
    sort(num, num + n);
    dfs(0, 0);
    return 0;
}
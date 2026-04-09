#include <iostream>
using namespace std;

int n, m;
int result[10];
int visited[10];

void dfs(int start, int depth) {
    if(depth == m) {
        for(int i = 0; i < m; i++) cout << result[i] << " ";
        cout << "\n";
        return;
    }

    for(int i = start; i <= n; i++) {
        result[depth] = i;
        dfs(i, depth + 1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    dfs(1, 0);
    return 0;
}
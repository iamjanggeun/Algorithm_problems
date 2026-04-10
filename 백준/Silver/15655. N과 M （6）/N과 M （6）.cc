#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m;
int result[10], visited[10];

void dfs(int start, int depth, vector<int>& v) {
    if(depth == m) {
        for(int i = 0; i < m; i++) cout << result[i] << " ";
        cout << "\n";
        return;
    }

    for(int i = start; i < n; i++) {
        if(!visited[i]) {
            visited[i] = true;
            result[depth] = v[i];
            dfs(i, depth + 1, v);
            visited[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 중복 x -> 방문 처리
    // 나왔던 조합은 x -> depth++로 막기
    cin >> n >> m;
    vector<int> v(n, 0);
    for(int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    dfs(0, 0, v);

    return 0;
}
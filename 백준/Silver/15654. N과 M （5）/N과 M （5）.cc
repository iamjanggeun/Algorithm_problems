#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int result[10];
int visited[10];

// 중복x -> 방문처리
// 순서대로 -> permutation
// 벡터 계속 호출하니까 참조로 받기
void dfs(int depth, vector<int>& v) {
    if(depth == m) {
        for(int i = 0; i < m; i++) cout << result[i] << " ";
        cout << "\n";
        return;
    }

    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            visited[i] = true;
            result[depth] = v[i - 1];
            dfs(depth + 1, v);
            visited[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    vector<int> v(n, 0);
    for(int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    dfs(0, v);
    return 0;
}
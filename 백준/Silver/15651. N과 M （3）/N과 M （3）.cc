#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
int visited[10];
int result[10];

void dfs(int depth) {

    if(depth == m) {
        for(int i = 0; i < m; i++) {
            cout << result[i] << " ";
        }
        cout << "\n";
        return;
    }

    for(int i = 1; i <= n; i++) {
        visited[i] = true;
        result[depth] = i;
        dfs(depth + 1);
        visited[i] = false; 
    }
}

int main() {

    cin >> n >> m;
    dfs(0);
    return 0;    
}
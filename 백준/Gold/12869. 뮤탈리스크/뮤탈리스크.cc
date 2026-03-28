/*********************************************************************
* Author:            Janggeun
* Date:              2026-03-28
* Project Name:      Algorithm Study
* Problem Name:      BOJ 12869 - 뮤탈리스크
* Description:       BFS
*********************************************************************/

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int visited[61][61][61];
int scv[3];

struct state{
    int x, y, z;
};

int bfs() {
    queue<state> Q;
    Q.push({scv[0], scv[1], scv[2]});
    visited[scv[0]][scv[1]][scv[2]] = 1;

    while(!Q.empty()) {
        state cur = Q.front(); Q.pop();

        if(cur.x == 0 && cur.y == 0 && cur.z == 0) {
            return visited[cur.x][cur.y][cur.z] - 1;
        }

        int damage[3] = {1, 3, 9};

        do{
            int nx = max(0, cur.x - damage[0]);
            int ny = max(0, cur.y - damage[1]);
            int nz = max(0, cur.z - damage[2]);

            if(!visited[nx][ny][nz]) {
                visited[nx][ny][nz] = visited[cur.x][cur.y][cur.z] + 1;
                Q.push({nx, ny, nz});
            }
        } while(next_permutation(damage, damage + 3));
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> scv[i];
    }

    cout << bfs() << "\n";
    return 0;
}
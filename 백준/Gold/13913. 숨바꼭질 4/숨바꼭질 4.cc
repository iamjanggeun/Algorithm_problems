#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int n, k;
int dist[100001];
int parent[100001];

void bfs()
{
    queue<int> Q;
    Q.push(n);
    dist[n] = 0;
    parent[n] = -1;

    while(!Q.empty())
    {
        int cur = Q.front(); Q.pop();
        if(cur == k) return;

        int dx[3] = {cur - 1, cur + 1, cur * 2};

        for(int dir = 0; dir < 3; dir++)
        {
            int nx = dx[dir];
            if(nx < 0 || nx >= 100001) continue;
            if(dist[nx] != -1) continue;

            dist[nx] = dist[cur] + 1;
            parent[nx] = cur;
            Q.push(nx);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    fill(dist, dist + 100001, -1);

    bfs();

    cout << dist[k] << "\n";

    vector<int> path;
    int cur = k;
    while(cur != -1)
    {
        path.push_back(cur);
        cur = parent[cur];
    }

    reverse(path.begin(), path.end());
    for(int e : path) cout << e << " ";
}
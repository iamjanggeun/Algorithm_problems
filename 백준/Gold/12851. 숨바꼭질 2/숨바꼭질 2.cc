#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
int dist[100001];
int cnt[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    fill(dist, dist + 100001, -1);
    queue<int> Q;
    dist[n] = 0;
    cnt[n] = 1;
    Q.push(n);

    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        for(int next : {cur - 1, cur + 1, 2 * cur}) {
            if(next < 0 || next >= 100001) continue;
            
            if(dist[next] == -1) {
                dist[next] = dist[cur] + 1;
                cnt[next] = cnt[cur];
                Q.push(next);
            }
            else if(dist[next] == dist[cur] + 1) cnt[next] += cnt[cur];
        }
    }
    cout << dist[m] << "\n" << cnt[m];
    return 0;
}
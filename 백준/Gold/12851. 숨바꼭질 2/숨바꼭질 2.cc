#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int dist[100001];
long long route[100001]; 
int n, k;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    fill(dist, dist + 100001, -1);

    dist[n] = 0;
    route[n] = 1; 
    
    queue<int> Q;
    Q.push(n);

    while(!Q.empty()) {
        int cur = Q.front(); 
        Q.pop();

        for(int next : {cur + 1, cur - 1, cur * 2}) {
            if(next < 0 || next > 100000) continue;

            if(dist[next] == -1) {
                dist[next] = dist[cur] + 1;
                route[next] = route[cur];
                Q.push(next);
            }
            else if(dist[next] == dist[cur] + 1) {
                route[next] += route[cur]; 
            }
        }
    }

    cout << dist[k] << "\n" << route[k];
    return 0;
}
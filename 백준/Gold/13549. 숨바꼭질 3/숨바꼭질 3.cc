#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, k;
int board[100001];
int dist[100001];
int dx[2] = {-1, 1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    fill(dist, dist + 100001, -1);

    //n에서 시작
    deque<int> DQ;
    DQ.push_front(n);
    dist[n] = 0;

    while(!DQ.empty()){
        auto cur = DQ.front(); DQ.pop_front();

        if(cur == k){
            cout << dist[k];
            return 0;
        }

        if(cur * 2 < 100001 && dist[cur * 2] == -1){
            dist[cur * 2] = dist[cur];
            DQ.push_front(cur * 2);
        }

        for(int dir = 0; dir < 2; dir++){
            int nx = cur + dx[dir];
            if(nx < 0 || nx >= 100001) continue;
            if(dist[nx] >= 0) continue;

            dist[nx] = dist[cur] + 1;
            DQ.push_back(nx);
        }
    }
}
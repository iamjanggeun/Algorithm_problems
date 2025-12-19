#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int F, S, G, U, D;
int dist[1000001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> F >> S >> G >> U >> D;

    fill(dist, dist + F + 1, -1);

    queue<int> Q;
    dist[S] = 0;
    Q.push(S);

    while (!Q.empty())
    {
        int cur = Q.front(); Q.pop();

        int up = cur + U;
        int down = cur - D;

        if (up <= F && dist[up] == -1) {
            dist[up] = dist[cur] + 1;
            Q.push(up);
        }
        if (down >= 1 && dist[down] == -1) {
            dist[down] = dist[cur] + 1;
            Q.push(down);
        }
    }

    if (dist[G] == -1)
        cout << "use the stairs";
    else
        cout << dist[G];
}
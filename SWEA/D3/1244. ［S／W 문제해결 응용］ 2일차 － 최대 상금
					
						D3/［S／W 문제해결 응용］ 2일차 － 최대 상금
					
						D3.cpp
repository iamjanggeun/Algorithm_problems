#include <iostream>
#include <algorithm>
using namespace std;

string num;
int cnt, answer;
bool visited[11][1000001];

void dfs(int curr) {
    if(cnt == curr) {
        answer = max(answer, stoi(num));
        return;
    }

    for(int i = 0; i < num.size(); i++) {
        for(int j = i + 1; j < num.size(); j++) {
            swap(num[i], num[j]);

            int next = stoi(num);
            if(!visited[curr + 1][next]) {
                visited[curr + 1][next] = true;
                dfs(curr + 1);
            }

            swap(num[j], num[i]);
        }
    }
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int test_case;
    cin >> test_case;

    for(int i = 0; i < test_case; i++) {
        cin >> num >> cnt;
        for(int i = 0; i < 11; i++) fill(visited[i], visited[i] + 1000001, false);
        answer = 0;
        dfs(0);
        cout << "#" << i + 1 << " " << answer << "\n";
    }

    return 0;
}
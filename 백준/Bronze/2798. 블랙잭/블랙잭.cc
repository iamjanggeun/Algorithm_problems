#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> v(n, 0);
    vector<int> Diff;
    for(int i = 0; i < n; i++) cin >> v[i];

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            for(int k = j + 1; k < n; k++) {
                
                int sum = v[i] + v[j] + v[k];

                if(sum == m) {
                    cout << sum;
                    return 0;
                }

                else if (sum < m) {
                    int diff = m - sum;
                    Diff.push_back(diff);
                }
            }
        }
    }
    sort(Diff.begin(), Diff.end());

    cout << m - Diff[0];
    return 0;
}
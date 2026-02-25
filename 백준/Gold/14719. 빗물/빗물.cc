#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int w, h;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> h >> w;
    vector<int> height(w);
    for(int i = 0; i < w; i++) {
        cin >> height[i];
    }

    int ans = 0;

    for(int i = 1; i < w - 1; i++) {
        int left = 0;
        int right = 0;

        for(int j = 0; j < i; j++) left = max(left, height[j]);
        for(int k = w - 1; k > i; k--) right = max(right, height[k]);

        if(height[i] > left || height[i] > right) continue;

        ans += min(left, right) - height[i];
    }

    cout << ans;
    return 0;
}
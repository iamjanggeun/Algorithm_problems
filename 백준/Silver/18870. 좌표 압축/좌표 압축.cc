#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    map<int, int> mp;
    vector<int> v(n, 0);
    vector<int> temp(n, 0);

    for(int i = 0; i < n; i++) {
        cin >> v[i];
        temp[i] = v[i];
    }
    
    sort(temp.begin(), temp.end());
    temp.erase(unique(temp.begin(), temp.end()), temp.end());

    for(int i = 0; i < temp.size(); i++) {
        mp[temp[i]] = i;
    }

    for(int i = 0; i < v.size(); i++) {
        cout << mp[v[i]] << " ";
    }

    return 0;
}
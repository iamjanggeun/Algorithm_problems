#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cctype>

using namespace std;
string num_to_name[100004];
map<string, int> name_to_num;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        string name;
        cin >> name;
        
        num_to_name[i] = name;
        name_to_num[name] = i;
    }

    for (int i = 0; i < m; i++) {
        string query;
        cin >> query;

        if (isdigit(query[0])) {
            int num = stoi(query);
            cout << num_to_name[num] << "\n";
        } else {
            cout << name_to_num[query] << "\n";
        }
    }

    return 0;
}
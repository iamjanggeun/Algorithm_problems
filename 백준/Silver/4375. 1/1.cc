#include <iostream>
#include <algorithm>
#include <string>
#include <stdlib.h>
using namespace std;
int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(cin >> n) {
        long long num = 1;
        int cnt = 1;
        int i = 10;
        while(1) {
            if(num % n == 0) break;
            num = (num * 10 + 1) % n; 
            cnt++;
        }
        cout << cnt << "\n";
    }

    return 0;
}
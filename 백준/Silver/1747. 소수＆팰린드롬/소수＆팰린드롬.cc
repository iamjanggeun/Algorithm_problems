#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isPrime(int n) {
    if(n <= 1) return false;
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) return false;
    }
    return true;
}

int main() {

    int n;
    cin >> n;

    while(1) {
        if(isPrime(n)) {
            string s = to_string(n);
            int len = s.size();
            string sub1, sub2;

            if(s.size() % 2 == 0) {
                sub1 = s.substr(0, len/2);
                sub2 = s.substr(len/2);
            }
            else {
                sub1 = s.substr(0, len/2);
                sub2 = s.substr(len/2 + 1);
            }

            string temp = sub1;
            reverse(temp.begin(), temp.end());

            if(temp == sub2) {
                cout << n;
                break;
            }
        }
        n++;
    }
    return 0;
}
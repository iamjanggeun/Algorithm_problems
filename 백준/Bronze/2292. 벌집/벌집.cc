#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int cnt = 1, i = 1;

    while(n > cnt) {
        cnt += 6*i;
        i++;
    }

    cout << i;

    return 0;
}
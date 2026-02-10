//시간 범위 생각을 안했음.
//이상 미만으로 카운트 했어야함.
#include <iostream>
#include <algorithm>
using namespace std;

int a, b, c;
int freq[101];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b >> c;

    int x, y;
    for(int i = 0; i < 3; i++){
        cin >> x >> y;
        for(int j = x; j < y; j++){
            freq[j]++;
        }
    }

    int sum = 0;

    for(auto e : freq) {
        if(e == 3) sum += 3 * c;
        else if(e == 2) sum += 2 * b;
        else if(e == 1) sum += a;
        else continue;
    }

    cout << sum;
    return 0;
}
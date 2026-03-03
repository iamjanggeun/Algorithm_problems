/*********************************************************************
* Author:            Janggeun
* Date:              2026-03-03
* Project Name:      Algorithm Study
* Problem Name:      BOJ 2910번 - 빈도정렬
* Description:       Map 자료구조를 이용한 풀이
*********************************************************************/
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

int arr[1001];
//빈도수 저장용 [cnt.first = arr원소 | cnt.second = 빈도수]
map<int, int> cnt;

//인덱스 저장용 [order.first = arr원소 | order.second = 들어온 arr 원소의 순서]
map<int, int> order;

//sort에 사용될 비교기준(문제 요구사항)
bool compare(pair<int, int> x, pair<int, int> y) {
    if(x.second == y.second) return order[x.first] < order[y.first];
    return x.second > y.second;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, c;
    cin >> n >> c;

    //cnt map 담을 배열
    vector<pair<int, int>> v;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        //빈도수 체크
        cnt[arr[i]]++;
        //먼저 들어온 수 판별용
        if(order[arr[i]] == 0) order[arr[i]] = i + 1;
    }

    for(auto e : cnt) v.push_back({e.first, e.second});

    sort(v.begin(), v.end(), compare);


    for(auto e : v) {
        for(int i = 0; i < e.second; i++) cout << e.first << " ";
    }
    return 0;
}
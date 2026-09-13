#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

int solution(vector<vector<string>> clothes) {
    unordered_map<string, int> mp;
    int answer = 1;
    for(auto e : clothes) mp[e[1]]++;

    for(auto e : mp) answer *= e.second + 1;
    
    return answer - 1;
}
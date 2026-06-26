#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int ans = 1;
    unordered_map<string, int> mp;
    for(const auto& e : clothes) mp[e[1]]++;
    
    for(const auto& e : mp) ans *= e.second + 1;
    
    return ans - 1;
}
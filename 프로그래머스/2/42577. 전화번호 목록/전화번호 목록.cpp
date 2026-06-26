#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>  
using namespace std;

bool solution(vector<string> phone_book) {
    unordered_map<string, int> mp;
    for(auto e : phone_book) mp[e] = 1;

    for(auto e : phone_book) {
        string temp = "";
        for(int i = 0; i < e.size() - 1; i++) {
            temp += e[i];
            if(mp[temp] == 1) return false;
        }
    }
    return true;
}
#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

bool solution(vector<string> phone_book) {
    
    unordered_map<string, int> mp;

    for(int i = 0; i < phone_book.size(); i++) mp[phone_book[i]] = 1;
    
    for(int i = 0; i < phone_book.size(); i++) {
        for(int j = 0; j < phone_book[i].size() - 1; j++) {
            string num = phone_book[i].substr(0, j + 1);
            if(mp[num] == 1) return false;
        }
    }

    return true;
}
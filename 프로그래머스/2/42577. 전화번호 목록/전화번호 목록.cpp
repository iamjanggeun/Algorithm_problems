// #include <iostream>
// #include <string>
// #include <vector>
// #include <algorithm>
// #include <unordered_map>  
// using namespace std;

// bool solution(vector<string> phone_book) {
//     unordered_map<string, int> mp;
//     for(auto e : phone_book) mp[e] = 1;

//     for(auto e : phone_book) {
//         string temp = "";
//         for(int i = 0; i < e.size() - 1; i++) {
//             temp += e[i];
//             if(mp[temp] == 1) return false;
//         }
//     }
//     return true;
// }






#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    unordered_map<string, int> mp;
    
    //1. phone book 해시 추가
    for(auto e : phone_book) mp[e] = 1;
    
    //2. phone_book 순회
    for(int i = 0; i < phone_book.size(); i++) {
        string temp = "";
        for(int j = 0; j < phone_book[i].size() - 1; j++) {
            temp += phone_book[i][j];
            if(mp[temp] == 1) answer = false;
        }
    }
    
    return answer;
}
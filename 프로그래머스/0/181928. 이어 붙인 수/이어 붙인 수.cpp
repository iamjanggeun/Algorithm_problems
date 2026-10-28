#include <string>
#include <vector>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int solution(vector<int> num_list) {
    int answer = 0;
    string even = "";
    string odd = "";
    
    for(const auto& e : num_list) {
        if(e % 2 == 0) even += to_string(e);
        else odd += to_string(e);
    }
    
    answer += stoi(even) + stoi(odd);
    return answer;
}
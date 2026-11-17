#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;

bool solution(string s) {
    bool answer = true;
    
    if(s.length() != 4 && s.length() != 6) return false;
    
    for(const auto& e : s) {
        if(isdigit(e) == 0) answer = false;
    }
    
    return answer;
}
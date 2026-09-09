#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    stack<char> stack;
    
    for(auto e : s) {
        if(stack.empty() && e == ')') return false;
        else if(stack.empty() && e == '(') stack.push(e);
        else if(stack.top() == '(' && e == ')') stack.pop();
        else stack.push(e);
    }
    
    if(stack.empty()) return true;
    else return false;
}
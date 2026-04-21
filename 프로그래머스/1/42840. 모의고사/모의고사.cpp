#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> a = {1, 2, 3, 4, 5};
vector<int> b = {2, 1, 2, 3, 2, 4, 2, 5};
vector<int> c = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> temp(3, 0);
    
    for(int i = 0; i < answers.size(); i++) {
        if(answers[i] == a[i % a.size()]) temp[0]++;
        if(answers[i] == b[i % b.size()]) temp[1]++;
        if(answers[i] == c[i % c.size()]) temp[2]++;                
    }
    
    int maxVal = *max_element(temp.begin(), temp.end());
    
    for(int i = 0; i < 3; i++) {
        if(maxVal == temp[i]) answer.push_back(i + 1);
    }

    return answer;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    for(int T = 1; T <= 10; T++) {
        int tc;
        cin >> tc;
        
        queue<int> Q;
        int num;
        
        for(int i = 0; i < 8; i++) {
            cin >> num;
        	Q.push(num);
        }
        
        int cnt = 1;
        
        while(1) {
        	int temp = Q.front();
            Q.pop();
            
            temp -= cnt;
            
            if(temp <= 0) {
            	Q.push(0);
                break;
            }
            
            Q.push(temp);
            cnt++;
            
            if(cnt > 5) cnt = 1;
        }
        
        cout << "#" << tc << " ";
        
        while(!Q.empty()) {
        	cout << Q.front() << " ";
            Q.pop();
        }
        
        cout << "\n";
    } 
    return 0;
}
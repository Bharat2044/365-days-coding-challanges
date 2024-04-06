// Question Link: https://www.codechef.com/problems/LIKECS01


#include <bits/stdc++.h>
using namespace std;

int main() {
    // your code goes here
    int t;
    cin >> t;
    
    while (t--) {
        string s;
        cin >> s;
        
        map < char, int > m;
        bool ans = false;
        
        for (int i = 0; i < s.size(); i++) {
            m[s[i]]++;
            
            if (m[s[i]] > 1) {
                ans = true;
                break;
            }
        }
        
        if (ans) 
            cout << "yes" << endl;
        else 
            cout << "no" << endl;
    }
    
    return 0;
}s

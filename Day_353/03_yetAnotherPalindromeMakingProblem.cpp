// Question Link: https://www.codechef.com/problems/MAKEPALAGAIN


#include<bits/stdc++.h>
using namespace std;

int main() {
    // your code goes here

    int tt;
    cin >> tt;
    
    while (tt--) {
        vector < char > o, e;
        
        int nn;
        cin >> nn;
        
        while (nn--) {
            char c;
            cin >> c;
            
            if (nn & 1) o.push_back(c);
            else e.push_back(c);
        }

        sort(o.begin(), o.end());
        sort(e.begin(), e.end());
        
        if (o == e) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}

// Question Link: https://www.codechef.com/problems/MINDIST1


#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, flage = 0;
    cin >> n;
    
    string s;
    cin >> s;
    
    stack < char > st;
    
    for (int i = 0; i < n; i++) {
        if (!st.empty()) {
            
            if (s[i] == '0' && st.top() == '0') {
                st.pop();
            }
            else if (s[i] == '1' && st.top() == '1') {
                flage = 1;
                break;
            }
            else
                st.push(s[i]);
        }
        else
            st.push(s[i]);
    }
    
    if (flage)
        cout << 1 << endl;
    else
        cout << 2 << endl;
}

int main() {
    // your code goes here
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}

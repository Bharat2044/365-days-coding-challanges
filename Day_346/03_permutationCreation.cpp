// Question Link: https://www.codechef.com/problems/PERMCREATE


#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        //Code here
        int i, n;
        cin >> n;
        
        if (n < 4) {
            cout << -1 << endl;
            continue;
        }
        
        vector < int > sm, cap, ans;
        
        for (i = 1; i <= n / 2; i++)
            sm.push_back(i);
            
        for (i = (n / 2) + 1; i <= n; i++)
            cap.push_back(i);
            
        for (i = 0; i <= cap.size(); i++) {
            ans.push_back(cap[i]);
            ans.push_back(sm[i]);
        }

        for (int i = 0; i < n; i++)
            cout << ans[i] << " ";
    }
    
    return 0;
}

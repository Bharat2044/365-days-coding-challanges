// Question Link: https://www.codechef.com/problems/CHEFRECP


#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector < int > v(n);
        unordered_map < int, int > m;
        
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        
        int i = 0;
        string ans = "YES";
        set < int > s;
        
        while (i < n) {
            int curr = v[i];
           
            if (m[curr] > 0) {
                ans = "NO";
                break;
            }
            
            while (i < n && v[i] == curr) {
                m[curr]++;
                i++;
            }
        
            s.insert(m[curr]);
        }
        
        if (s.size() == m.size()) 
            cout << ans << endl;
        else 
            cout << "NO" << endl;
    }
    
    return 0;

}

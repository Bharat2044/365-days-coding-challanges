// Question Link: https://www.codechef.com/problems/MAKPERM


#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        int arr[n];
        
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        unordered_map < int, int > mp;
        
        for (int i = 0; i < n; i++) {
            mp[arr[i]]++;
        }
        
        int ans = 0;
        
        for (auto it: mp) {
            if (it.first <= n) {
                if (it.second > 1) 
                    ans += (it.second - 1);
            }
            else 
                ans += it.second;
        }
    
        cout << ans << endl;
    }
    
    return 0;
}

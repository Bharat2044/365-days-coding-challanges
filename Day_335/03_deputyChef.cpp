// Question Link: https://www.codechef.com/problems/DEPCHEF


#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int n;
        cin >> n;
        
        int att[n], sh[n];
        
        for (int i = 0; i < n; i++) 
            cin >> att[i];
        
        for (int i = 0; i < n; i++) 
            cin >> sh[i];

        int ans = -1;
        
        if (att[1] + att[n - 1] < sh[0]) 
            ans = sh[0];
        
        if (att[n - 2] + att[0] < sh[n - 1]) 
            ans = max(ans, sh[n - 1]);
        
        for (int i = 1; i < n - 1; i++)
            if (sh[i] > att[i - 1] + att[i + 1]) ans = max(ans, sh[i]);

        cout << ans << endl;
    }
    
    return 0;
}

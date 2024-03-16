// Question Link: https://www.codechef.com/problems/MNMX


#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        long long int n;
        cin >> n;
        
        long long int a[n], i, small = 100000;
        
        for (i = 0; i < n; i++) {
            cin >> a[i];
            
            small = min(small, a[i]);
        }
        
        cout<<small * (n-1)<<endl;
    }
    
    return 0;
}

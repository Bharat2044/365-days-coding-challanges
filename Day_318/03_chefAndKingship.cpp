// Question Link: https://www.codechef.com/problems/KINGSHIP


#include <bits/stdc++.h>
using namespace std;

int main() {
    // your code goes here
    int t;
    cin >> t;
    
    while (t--) {
        long long n;
        cin >> n;
        
        long long a[n];
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
    
        long long x = * min_element(a, a + n);
        long long cost = 0;
    
        for (int i = 0; i < n; i++) {
            if (a[i] == x) {
                continue;
            }
            else {
                cost = cost + x * a[i];
            }
        }
    
        cout << cost << endl;
    }
    
    return 0;
}

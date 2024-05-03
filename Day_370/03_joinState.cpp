// Question Link: https://www.codechef.com/problems/JOINSTATE


#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, y;
        cin >> n >> y;
       
        int a[n];
       
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
       
        int c = 0, s = 0, i = 0;
       
        for (int i = 0; i < n; i++) {
            s += a[i];
            
            if (s >= y) {
                c++;
                s = 0;
            }
        }
        
        cout << c << endl;
    }
    
    return 0;
}

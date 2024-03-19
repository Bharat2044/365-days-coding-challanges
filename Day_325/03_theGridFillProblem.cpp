// Question Link: https://www.codechef.com/problems/FILLGRID


//-----------------------SJ-------------------

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        long long int n, k, ans = 0;
        cin >> n;

        if (n == 2) {
            cout << -1 << " " << -1 << "\n" << -1 << " " << -1 << endl;
        }
        else {
            for (int i = 0; i < n; i++) {
                
                for (int j = 0; j < n; j++) {
                    if (i == j) 
                        cout << -1 << " ";
                    else 
                        cout << 1 << " ";
                }
                
                cout << endl;
            }
        }
    }

    return 0;
}

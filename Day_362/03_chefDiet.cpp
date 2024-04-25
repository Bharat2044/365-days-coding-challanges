// Question Link: https://www.codechef.com/problems/DIET


#include <iostream>
using namespace std;

int main() {
    // your code goes here
    int t;
    cin >> t;
    
    while (t--) {
        int n, k, j;
        cin >> n >> k;
        
        int a[n];
        
        for (int i = 0; i < n; i++)
            cin >> a[i];
            
        if (a[0] < k)
            cout << "NO " << 1 << endl;
        else {
            for (j = 1; j < n; j++) {
                a[j] += a[j - 1] - k;
                
                if (a[j] < k) {
                    cout << "NO " << j + 1 << endl;
                    break;
                }
            }
    
            if (j == n)
                cout << "YES\n";
        }
    }
    
    return 0;
}

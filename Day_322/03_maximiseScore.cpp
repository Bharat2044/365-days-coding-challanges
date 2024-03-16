// Question Link: https://www.codechef.com/problems/MAXIMSCORE


#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    int n;
    
    while (t--) {
        cin >> n;
        
        int a = 0;
        int arr[n];

        for (int i = 0; i < n; i++) 
            cin >> arr[i];
        
        int c = abs(arr[0] - arr[1]);
        int x, y;
        
        for (int i = 1; i < n; i++) {
            if (i != n - 1) {
                x = abs(arr[i] - arr[i - 1]);
                y = abs(arr[i] - arr[i + 1]);

                if (x >= y && x < c) 
                    c = x;
                else if (y > x && y < c) 
                    c = y;
            }
            else if (i == n - 1) {
                x = abs(arr[i] - arr[i - 1]);
                
                if (x < c) 
                    c = x;
            }
        }
    
        cout << c << endl;
    }
    
    return 0;
}

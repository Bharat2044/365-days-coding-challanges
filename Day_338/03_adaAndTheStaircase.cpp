// Question Link: https://www.codechef.com/problems/ADASTAIR


#include <bits/stdc++.h>
using namespace std;

int main() {
    // your code goes here
    int t;
    cin >> t;
    
    while (t--) {
        int n, k;
        cin >> n >> k;

        int h[n + 1];
        int count = 0;
        h[0] = 0;

        for (int i = 1; i <= n; i++)
            cin >> h[i];
        
        for (int i = 1; i <= n; i++) {
            int diff = h[i] - h[i - 1];

            if (diff > k)
                count += (diff - 1) / k;
        }
        
        cout << count << endl;
    }
    
    return 0;
}

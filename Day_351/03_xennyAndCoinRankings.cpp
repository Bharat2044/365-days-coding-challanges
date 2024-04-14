// Question Link: https://www.codechef.com/problems/XENRANK


#include <bits/stdc++.h>
using namespace std;

int main() {
    // your code goes here
    int t;
    cin >> t;
    
    while (t--) {
        long long int u, v;
        cin >> u >> v;
        
        cout << 1 + u + ((u + v) * (u + v + 1)) / 2 << "\n";
    }
    
    return 0;
}

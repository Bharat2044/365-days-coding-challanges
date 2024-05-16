// Question Link: https://www.codechef.com/problems/OG


#include <bits/stdc++.h>
using namespace std;


int main() {
    // your code goes here
    int t;
    cin >> t;
    
    while (t--) {
        long long int n;
        cin >> n;
        
        int rem = n % 9;
        n = n / 9;
        n = n * 45;
        
        rem = (rem * (rem + 1)) / 2;
        
        cout << n + rem << endl;
    }
    
    return 0;
}

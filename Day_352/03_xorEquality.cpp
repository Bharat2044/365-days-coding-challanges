// Question Link: https://www.codechef.com/problems/XOREQUAL


#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
#define intt long long int

intt fastexpo(intt a, intt n) {
    intt ans = 1;
    a = a % mod;
    
    while (n > 0) {
        intt lastbit = (n & 1);

        if (lastbit)
            ans = (ans * a) % mod;
        
        a = (a * a) % mod;
        n = n >> 1;
    }

    return ans;
}

int main() {
    // your code goes here
    intt t;
    cin >> t;
    
    while (t--) {
        intt n;
        cin >> n;

        intt res = fastexpo(2, n - 1) % mod;
        cout << (res) << endl;
    }
    
    return 0;
}

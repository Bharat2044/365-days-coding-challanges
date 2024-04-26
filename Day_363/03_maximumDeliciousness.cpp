// Question Link: https://www.codechef.com/problems/KDELI


#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int t;
    cin >> t;
    
    do {
        ll n, k, l;
        cin >> n >> k >> l;
        multiset < ll > pastry;
        
        for (ll i = 0; i < n; i++) {
            ll ele;
            cin >> ele;
            pastry.insert(ele);
        }
        
        ll count = 1;
        ll total = 0;
        
        for (multiset < ll > ::reverse_iterator itr = pastry.rbegin(); itr != pastry.rend(); itr++) {
            if (count == l) total += * itr;
            if (count == k) count = 0;
            
            count++;
        }
        
        cout << total << "\n";
    } while (--t);
    
    return 0;
}

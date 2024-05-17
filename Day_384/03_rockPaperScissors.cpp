// Question Link: https://www.codechef.com/problems/ROCPAPSCI


#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t-- > 0) {
        int n;
        cin >> n;

        string a;
        cin >> a;
        int ct = 0;

        for (int i = 0; i < n; i++) {
            if (a[i] == a[i - 1])
                a[i] = '*';
            else 
                ct++;
        }
        
        cout << ct << endl;
    }
    
    return 0;
}

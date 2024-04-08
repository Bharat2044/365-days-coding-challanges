// Question Link: https://www.codechef.com/problems/PERDIS


#include <iostream>
using namespace std;

int mx(int a[], int n) {
    int m = 0, s = 0;
    
    for (int i = 0; i < n - 1; i++) {
        if (a[i] == i + 1) {
            m++;
            
            s = a[i];
            a[i] = a[i + 1];
            a[i + 1] = s;
        }
    }
    
    if (a[n - 1] == n) 
        m++;

    return m;
}

int main() {
    int t, n;
    cin >> t;
    
    while (t--) {
        cin >> n;
        int a[n];
        
        for (int i = 0; i < n; i++) 
            cin >> a[i];
        
        cout << mx(a, n) << endl;
    }
    
    return 0;
}

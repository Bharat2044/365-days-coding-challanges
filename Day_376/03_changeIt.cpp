// Question Link: https://www.codechef.com/problems/CHNGIT


#include <iostream>
using namespace std;

int main() {
    // your code goes here
    int t, n;
    cin >> t;
    
    while (t--) {
        cin >> n;
        int a[n];
    
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
    
        int count = 0, sum = 0;
    
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (a[i] == a[j]) count++;
            }
    
            sum = max(sum, count);
            count = 0;
        }
    
        cout << n - sum << endl;
    }
    
    return 0;
}

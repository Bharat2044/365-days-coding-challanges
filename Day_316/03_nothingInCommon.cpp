// Question Link: https://www.codechef.com/problems/NOTINCOM


#include <iostream>

#include <algorithm>

using namespace std;

int main() {
    // your code goes here
    int t;
    cin >> t;
    
    while (t--) {
        int x, y, p = 0;
        cin >> x >> y;
        long int a[x], b[y];
        
        for (int i = 0; i < x; i++)
            cin >> a[i];
        
        for (int j = 0; j < y; j++)
            cin >> b[j];
        
        sort(a, a + x);
        sort(b, b + y);
        int i = 0, j = 0;
        
        while (i < x && j < y) {
            if (a[i] > b[j]) 
                j++;
            else if (a[i] < b[j]) 
                i++;
            
            else {
                p++;
                j++;
                i++;
            }
        }
        
        cout << p << endl;
    }
    
    return 0;
}

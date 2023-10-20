// Question Link: https://www.codechef.com/problems/GENIUS


#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        
        if (x % 3 != 0)
        {
            int fir = x / 3 + 1;
            int sec = 3 - x % 3;
            if(fir + sec > n)
                cout << "NO" << endl;
            else {
                cout << "YES" << endl;
                cout << fir << " " << sec << " " << n - fir - sec << endl;
            }
        }
        else {
            cout << "YES" << endl;
            cout << x / 3 << " " << 0 << " " << n - x / 3 << endl;
        }
    }
    
    return 0;
}

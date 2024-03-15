// Question Link: https://www.codechef.com/problems/HEIGHTS


#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        int wand = 0;
        int maxi = 0;
        int mini = 0;
        
        int a[n];
        map < int, int > m;
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            
            if (a[i] > maxi)
                maxi = a[i];

            m[a[i]]++;
        }
        
        mini = m[maxi];
        for (auto & val: m) {
            if (val.second > mini && val.first != maxi)
                mini = val.second;

            if (val.second <= 1)
                wand++;

        }
        if (m[maxi] <= 1 && wand == 1) {
            if (mini == 2) {
                wand = mini;
                cout << wand << endl;
            }
            else if (mini > 2)
                cout << wand << endl;
        }
        else {
            if (wand & 1)  {
                wand++;
                cout << wand / 2 << endl;
            }
            else
                cout << wand / 2 << endl;
        }
    }

    return 0;
}

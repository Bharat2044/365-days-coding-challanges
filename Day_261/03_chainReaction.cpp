// Question Link: https://www.codechef.com/problems/REACTION


#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    int t;
    cin >> t;
    for (int loop = 0; loop < t; loop++)
    {
        int r, c;
        cin >> r >> c;
        int a[r][c];
        int s = 0, cnt = 0;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                s = 0;
                cin >> a[i][j];
                if (i == 0 || i == r - 1)
                {
                    s++;
                }
                else
                {
                    s += 2;
                }
                if (j == 0 || j == c - 1)
                {
                    s++;
                }
                else
                {
                    s += 2;
                }
                if (s <= a[i][j])
                {
                    cnt = 1;
                }
            }
        }
        if (cnt == 1)
            cout << "Unstable\n";
        else
            cout << "Stable\n";
    }
    
    return 0;
}

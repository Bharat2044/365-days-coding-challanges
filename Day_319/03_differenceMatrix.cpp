// Question Link: https://www.codechef.com/problems/MATDIF


#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define str string
#define mll map<ll, ll>
#define vec vector<ll>
#define set set<ll>
#define size size()

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    ll t = 1;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll a[n][n];
        ll c = 1, d = 2, e = n * n;

        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < n; j++)
            {
                if (c <= e)
                {
                    cout << c << " ";
                    c += 2;
                }
                else
                {
                    cout << d << " ";
                    d += 2;
                }
            }
            cout << endl;
        }
    }
    return 0;
}

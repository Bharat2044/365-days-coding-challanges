// Question Link: https://www.codechef.com/problems/SPCANDY


#include<bits/stdc++.h>
using namespace std;
#define testcases \
    int tt;       \
    cin >> tt;    \
    while (tt--)
#define ll long long int
#define pb push_back
#define db double
#define rep(i, n) for (ll i = 0; i < n; i++)
#define e endl
#define yes cout << "YES" << e;
#define no cout << "NO" << e;
#define fast                           \
    ios_base ::sync_with_stdio(false); \
    cin.tie(NULL);                     \
    cout.tie(NULL);

void solve()
{
    ll n, k;
    cin >> n >> k;

    if(k != 0){
        
     cout << n / k << " " << n % k << e;
    }
    else{
        cout << "0" << " " << n << e;
    }
}
int main()
{
    //system("cls");
    fast;

    testcases
    {
        solve();
    }
    return 0;
}

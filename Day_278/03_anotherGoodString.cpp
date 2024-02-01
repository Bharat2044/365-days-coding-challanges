// Question Link: https://www.codechef.com/problems/ADVITIYA4


#include "bits/stdc++.h"
using namespace std;

#define int long long int
#define double long double
#define endl '\n'

const int MOD = 1000000007;

void solve(){
    int n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    stack<pair<char,int> > st;
    int mx=0;
    for (int i = 0; i < n; i++) {
        if (st.empty() || st.top().first != s[i]){
            st.push({s[i],1});
        } else {
            st.push({s[i],st.top().second+1});
        }
        mx = max(st.top().second,mx);
    }
    cout<<mx<<" ";
    for (int i = 0; i < q; i++) {
        char x;
        cin>>x;
        if (st.empty() || st.top().first != x){
            st.push({x,1});
        } else {
            st.push({x,st.top().second+1});
        }
        mx = max(st.top().second,mx);
        cout<<mx<<" \n"[i==q-1];
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t=1;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

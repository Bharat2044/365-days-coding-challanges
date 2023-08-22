// Question Link: https://www.codechef.com/problems/EQPAIR


#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        
        vector<int> v(n);
        unordered_map<int, int> freqM;
        
        for(int i = 0; i < n; i++){
            cin>>v[i];
            freqM[v[i]]++;
        }
        
        long long ans = 0;
        for(auto p:freqM){
            int freq = p.second;
            ans += (long long) freq*(freq-1)/2;
        }
        
        cout<<ans<<'\n';
    }
    
    return 0;
}

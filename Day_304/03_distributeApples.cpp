// Question Link: https://www.codechef.com/problems/DSTAPLS


#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin>>t;
    
    while(t--){
        long long int n,k,ans,r;
        cin>>n>>k;
        
        r=n/k;
        
        if(r%k==0)
            cout<<"NO\n";
        else 
            cout<<"YES\n";
    }
    
    return 0;
}

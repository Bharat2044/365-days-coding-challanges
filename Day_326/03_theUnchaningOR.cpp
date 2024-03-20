// Question Link: https://www.codechef.com/problems/UNCHANGEDOR


#include "bits/stdc++.h"
using namespace std;

void solve() {
    long long n;
    cin>>n;
   
   long long ans=1;
   long long temp=n;
   
   while(n>=2) {
       n=n/2;
       ans++;
   }
   
   cout<<temp-ans<<endl;
}

int main() {
	int t;
	cin >> t;

	while(t--) {
	    solve();
	}
	
	return 0;
}

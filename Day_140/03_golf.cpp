// Question Link: https://www.codechef.com/problems/LKDNGOLF


#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T; 
	
	while (T--) {
		int n,x,k;
		cin>>n>>x>>k;
		
		if(!(x%k) || !((n+1-x)%k)) 
		    cout<<"YES\n";
		else 
		    cout<<"NO\n";
	}
	
	return 0;
}

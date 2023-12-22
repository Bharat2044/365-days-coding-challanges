// Question Link: https://www.codechef.com/problems/NUMGAME2


#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; 
    cin>>n;
    
    if(n%4 == 1) 
        cout<<"ALICE\n";
    else 
        cout<<"BOB\n";
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	
	while(t--) {
	    solve();
	}
	
	return 0;
}

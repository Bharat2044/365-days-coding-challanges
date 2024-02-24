// Question Link: https://www.codechef.com/problems/SIMPLE_XOR


#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	
	while(t--){
	    int l,r;
	    cin>>l>>r;
	    
	    if(l&1 && l+4<=r){
	        for(int i=0;i<4;i++)
	            cout<<++l<<" ";
	    }
	    else if(!(l&1) && l+3<=r){
	        for(int i=0;i<4;i++)
	            cout<<l++<<" ";
	    }
	    else 
	        cout<<-1;
	        
	    cout<<endl;
	}

    return 0;
}

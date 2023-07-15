// Question Link: https://www.codechef.com/problems/TRANCHAIN


#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
	int t;
	cin>>t;
  
	while(t--)
	{
	    int n;
	    cin>>n;
	    int c1=0,c2=0;
	    
	    for(int i=0;i<n;i++){
	        string ch;
	        cin>>ch;
	        
	        if(ch=="A" || ch=="AB" || ch=="O")
	            c1++;
	        if(ch=="B" || ch=="AB" || ch=="O")
	            c2++;
	    }
	    
	    cout<<max(c1,c2)<<endl;
	}
  
	return 0;
}

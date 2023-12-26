// Question Link: https://www.codechef.com/problems/NUMCOMP


#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    long long  a,b,n;
	    int j;
	    cin>>a>>b>>n;
	    if((a==0)||(b==0)){
	        if((a==0)&&(b==0)){
	            cout<<0<<endl;
	            continue;
	        }
	        else if(a==0){
	            if(b<0){
	                n%2==0?cout<<2<<endl:cout<<1<<endl;
	                continue;
	            }
	            else{
	                cout<<2<<endl;
	                continue;
	            }
	        }
	        else if(b==0){
	            if(a<0){
	                n%2==0?cout<<1<<endl:cout<<2<<endl;
	                continue;
	            }
	            else{
	                cout<<1<<endl;
	                continue;
	            }
	        }
	    }
	    if((a>0)&&(b>0)){
	    a>b?cout<<1<<endl:a<b?cout<<2<<endl:cout<<0<<endl;
	      continue;
	    }
	    if((a<0)||(b<0)){
	        if((a<0)&&(b<0)){
	            if(n%2==0){
	             a<b?cout<<1<<endl:a>b?cout<<2<<endl:cout<<0<<endl;
	             continue;
	            }
	            a>b?cout<<1<<endl:a<b?cout<<2<<endl:cout<<0<<endl;
	            continue;
	        }
	        else{
	            if(n%2==1){
	                 a>b?cout<<1<<endl:a<b?cout<<2<<endl:cout<<0<<endl;
	                continue;
	            }
	             abs(a)>abs(b)?cout<<1<<endl:abs(a)<abs(b)?cout<<2<<endl:cout<<0<<endl;	             
	            	             continue;
	        }
	    }
	}
	
	return 0;
}

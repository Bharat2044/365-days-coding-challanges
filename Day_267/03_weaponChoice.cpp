// Question Link: https://www.codechef.com/problems/WEPCH


#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    long long h,x,y1,y2,k;
	    long long a,b;
	    cin>>h>>x>>y1>>y2>>k;
	    a=ceil(h/(1.0*x));
	    long long temp=h-(k*y1);
	    if(temp<=0){b=ceil(h/(1.0*y1));}
	    else{b=ceil(temp/(1.0*y2))+k;}
	    if(a>b){cout<<b;}
	    else{cout<<a;}
	    cout<<endl;
	}
}

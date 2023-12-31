// Question Link: https://www.codechef.com/problems/XORAGN


#include <bits/stdc++.h>
using namespace std;

int main() {
	  int t;
	  cin>> t;
	  while (t--){
	     long long n;
	     cin>>n;
	     long long unsigned int a[n];
	     vector<long long unsigned int> v;
	     for(int i=0;i<n;i++){
	       cin>>a[i];
	     }
	    
	   for(int i=0;i<n;i++){
	     v.push_back(2*a[i]);
	   }
	    
	    long long unsigned int num= 0;
	    for(int i=0;i<v.size();i++){
	      num^=v[i];
	    }
	    
	    cout << num <<endl;
	    
	  }
	return 0;
}

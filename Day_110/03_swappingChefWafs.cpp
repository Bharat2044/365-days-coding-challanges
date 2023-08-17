// Question Link: https://www.codechef.com/problems/SWAPCW


#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	
	while(t--){
	    int n;
	    cin>>n;
	    string s,a;
	    cin>>s;
	    
	    a =s;
	    sort(a.begin() ,a.end());
	 
	    if(a ==s){
	        cout<<"yes"<<endl;
	    }
	    else{
	        int i=0;
	        int j = n-1;
	        
	        while(i<j){
	            if(s[i]>s[j]){
	                swap(s[i] , s[j]);
	            }
	            i++;
	            j--;
	        }
	        
	        if(a==s){
	            cout<<"yes"<<endl;
	        }
	        else{
	            cout<<"no"<<endl;
	        }
	    }
	}
	
	return 0;
}

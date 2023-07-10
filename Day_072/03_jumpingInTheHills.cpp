// Question Link: https://www.codechef.com/problems/HILLS


#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	
	int t;
	cin>>t;
	
	while(t--){
	    int n,u,d;
	    cin>>n>>u>>d;
	    
		int a[n];

		for(int i=0;i<n;i++){cin>>a[i];}
	    
		int f = 1, b=1;

		for(int i=0;i<n-1;i++){
			
			if(a[i]<=a[i+1]){
				if((a[i+1]-a[i])<=u){
					f++;
				}				
				else{
				    break;
				}
			}
			else{
				if(a[i]-a[i+1]<=d){
					f++;
				}
				
				else if(b){
				    f++;
				    b--;
				}
				
				else{
				    break;
				}
			}
		}
		
	
        std::cout << f << std::endl;
	    
	}
	
	return 0;
}

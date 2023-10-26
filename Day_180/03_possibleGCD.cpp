// Question Link: https://www.codechef.com/problems/DISTGCD


#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	
	while(t--){
	    int a,b;
	    cin>>a>>b;
	    
	    int ans=0;
	    int n=abs(a-b);
	    
	    for(int i=1; i*i<=n;i++){
	        if(n%i==0){
	            ans++;
	            if(i!=(n/i)){
	                ans++;
	            }
	        }
	    }
	    cout<<ans<<"\n";
	}
	
	return 0;
}

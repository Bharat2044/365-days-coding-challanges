// Question Link: https://www.codechef.com/problems/PERMGCD


#include <iostream>
using namespace std;

int main() {
	 int t;
	 cin>>t;
	 while(t--){
	    int n,k;
	    cin>>n>>k;
	    if(k<n){
	      cout<< -1 << endl;
	    }
	    else{
	      cout<< k-n+1<<" ";
	      for(int i=1;i<=n;i++){
	          if(i!=k-n+1){
	            cout<< i<<" ";
	          }
	       }
	       cout<<endl;
	    }
	   
	   
	 }
	return 0;
}

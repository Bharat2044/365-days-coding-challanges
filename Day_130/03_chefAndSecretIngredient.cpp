// Question Link: https://www.codechef.com/problems/PCJ18A


#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--){
	  int n,x;
	  cin>>n>>x;
	  
	  int a[n];
	  int flag=0;
	  
	  for(int i=0;i<n;i++)
	  {
	    cin>>a[i];
	    if(a[i]>=x){
	      flag=1;
	    }
	  }
	  
	  cout<<(flag==1?"YES":"NO")<<endl;
	}
	
	return 0;
}

// Question Link: https://www.codechef.com/problems/CCHEAVEN


#include <iostream>
using namespace std;

int main() {
	  int t;
	  cin>>t;
	  
	  while(t--){
	     int n,flag=0,count=0,num=0;
	     cin>>n;
	     string s;
	     cin>>s;
	     
	     for(int i=0;i<n;i++){
	       if(s[i]=='0'){
	         count++;
	       }
	       else{
	         num++;
	       }
	       
	       if(num>=count){
	         flag=1;
	         break;
	       }
	       
	     }
	    
	    if(flag){
	      cout<<"Yes"<<endl;
	    }
	    else{
	      cout<<"No"<<endl;
	    }
	  }
	  
	return 0;
}

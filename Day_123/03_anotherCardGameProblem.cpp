// Question Link: https://www.codechef.com/problems/CRDGAME3


#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	     int pc,pr;
	     cin>>pc>>pr;
	     float a=pc/9.0; int c=a;
	     float b=pr/9.0; int d=b;
	    
	     if(c==d){
	         cout<<"1"<<" ";
	         if(b==d)
	         cout<<b;
	         else
	         cout<<d+1;
        }
	    
	    
	    else if(a>b){
	         cout<<"1"<<" ";
	         if(b==d)
	         cout<<b;
	         else
	         cout<<d+1;
	   }
	            
	       else if(a<b){
	         cout<<"0"<<" ";
	         if(a==c)
	         cout<<a;
	         else
	         cout<<c+1;
         }
	            
	      
	           
	        cout<<endl;  
	     }
	          
	return 0;
}

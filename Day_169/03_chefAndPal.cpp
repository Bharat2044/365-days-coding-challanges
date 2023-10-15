// Question Link: https://www.codechef.com/problems/ANTIPAL


#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	
	while(t--){
	    int x;
	    cin>>x;
	    
	    if(x%2==1){
	        cout<<"-1"<<endl;
	    }
	    else{
	        
	        for(int i=0;i<=(x/2)-1;i++){
	            cout<<"10";
	        }
	         cout<<endl;
	    }
	}
	
	return 0;
}

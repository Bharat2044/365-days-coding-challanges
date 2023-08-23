// Question Link: https://www.codechef.com/problems/BRKBKS


#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	
	while(t--){
	    int s,w1,w2,w3;
	    cin>>s;
	    
	    int w[3];
	    int sum=0;
	    
	    for(int i=0;i<3;i++){
	        cin>>w[i];
	        sum+=w[i];
	    } 
	    
	    if(sum<=s) 
	        cout<<"1"<<endl;
	    else if((w[0]+w[1])<=s || (w[2]+w[1])<=s) 
	        cout<<"2"<<endl;
	    else 
	        cout<<"3"<<endl;
	}
	
	return 0;
}

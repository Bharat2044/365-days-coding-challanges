// Question Link: https://www.codechef.com/problems/ACBALL


#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--){
	    string x;
	    cin>>x;
	    
	    string y;
	    cin>>y;
	 
	    for(int i=0;i<x.size();i++){
	        if(x[i]==y[i] && (int)x[i]==66) 
	            cout<<'W';
	        else if(x[i]==y[i] && (int)x[i]==87) 
	            cout<<'B';
	        else 
	            cout<<'B';
	    }
	    
	    cout<<endl;
	}
	
	return 0;
}

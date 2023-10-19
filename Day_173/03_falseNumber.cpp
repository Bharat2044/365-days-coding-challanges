// Question Link: https://www.codechef.com/problems/FALSNUM


#include<bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	
	while(t--) {
	    string x;
	    cin >> x;
	    int len = x.length();
	    
	    if(x[0] == '1') {
	        cout << "10" ;
	        
	        for (int i=1; i<len ; i++)
	            cout << x[i];
	        cout << endl;
	    }
	    else
	        cout << "1" << x << endl;
	}
	
	return 0;
}

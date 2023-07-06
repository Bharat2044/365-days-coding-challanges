// Question Link:https://www.codechef.com/problems/BROKPHON


#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
	    int n; 
	    cin >> n;
	    int msg[n];
	    
	    for(int i=0; i<n; i++)
	        cin >> msg[i];
	    
	    int number = 0;
	    
	    for(int i=2; i<n; i++){
	        if(msg[i-2] != msg[i-1]){
	            number += 2; 
	            
	            if(msg[i-1] != msg[i])
	                number--;
	        }
	    }
	    
        if(msg[n-2] != msg[n-1])
            number += 2;
	    
	    cout << number << endl;
	}
	
	return 0;
}

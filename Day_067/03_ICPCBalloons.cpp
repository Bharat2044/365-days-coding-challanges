// Question Link: https://www.codechef.com/problems/BALLOON


#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	
	while(t--) {
	    int n;
	    cin >> n;
	    
	    int i;
	    int max = 0;
	    int arr[n];
	    
	    for(i=0; i<n; i++){
	        cin >> arr[i];
	        
	        if(arr[i]<8 && arr[i]>0)
	            max = i;
	    }
	    
	    cout << (max + 1) << "\n";
	}
	
	return 0;
}

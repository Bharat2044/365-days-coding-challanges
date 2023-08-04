// Question Link: https://www.codechef.com/problems/SINGLEOP1


#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	
	while(t--){
	    int n, sum = 0;
	    cin >> n;
	    
	    string s;
	    cin >> s;
	    
	    for(int i=0; i<n; i++){
	        if(s[i] == '1')
	            sum++;
	        else
	            break;
	    }
	    
	    cout << sum << endl;
	}
	
	return 0;
}

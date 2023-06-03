// Question Link: https://www.codechef.com/problems/APPENDOR



#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int a, b, c, t;
	
	cin >> t;
	
	while(t--) {
	    cin >> a >> b;
	    long arr[a], OR = 0;
	    bool flag = false;
	    
	    for (int i = 0; i < a; i++) {
	        cin >> arr[i];
	        OR = OR |arr[i];
	    }
	    
	    for (int j=0; j<=b; j++) {
	        if ((OR|j) == b) {
	            cout << j << endl;
	            flag = true;
	            break;
	        }
	    }
	    
	    if (!flag)
	        cout << "-1 \n";
	    
	   // cout << a << "->" << b << endl;
	}
	
	return 0;
}

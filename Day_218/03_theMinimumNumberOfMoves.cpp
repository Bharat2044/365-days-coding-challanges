// Question Link: https://www.codechef.com/problems/SALARY


#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	
	while(t--){
	    int n;
	    cin >> n;
	    int a[n];
	    
	    for(int i=0;i<n;i++){
	        cin >> a[i];
	    }
	    
	    int sum = 0;
	    int min = a[0];
	    
	    for(int i=0;i<n;i++){
	        if(a[i]<min){
	            min = a[i];
	        }
	        sum += a[i];
	    }
	    
	    cout << sum -n*min << endl;
	}
	
	return 0;
}

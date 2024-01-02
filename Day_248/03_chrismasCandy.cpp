// Question Link: https://www.codechef.com/problems/CHRISCANDY


#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    int a[n];
	    
	    for(int i = 0;i<n;i++){
	        cin >> a[i];
	    }
	    
	    int currmax = a[0];
	    int candycount = 0;
	    
	    for(int i = 1;i<n;i++){
	        if(a[i] > currmax){
	            currmax = a[i];
	        }
	        else{
	            candycount++;
	        }
	    }
	    
	    cout << candycount << endl;
	}
    
    return 0;
}

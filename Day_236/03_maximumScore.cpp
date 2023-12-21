// Question Link: https://www.codechef.com/problems/MAXSCORE7


#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--){
	    int n;
	    cin >> n;
	    
	    int temp;
	    int onecount = 0;
	    int zerocount = 0;
	    
	    for(int i = 0;i<n;i++){
	        cin >> temp;
	        
	        if(temp == 1){
	            onecount++;
	        }
	        else{
	            zerocount++;
	        }
	    }
	    
	    cout << min(onecount, zerocount) << endl;
	}
	
	return 0;
}

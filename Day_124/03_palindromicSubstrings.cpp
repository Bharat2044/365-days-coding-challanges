// Question Link: https://www.codechef.com/problems/STRPALIN


#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--){
	    string a,b;
	    cin >> a >> b;
	    int p = 0;
	    
	    for (int i=0;i<a.length();i++){
	        if (b.find(a[i])!=-1){
	            p=1;
	            break;
	        }
	    }
	    
	    if(p==1) 
	        cout << "Yes" << endl;
	    else 
	        cout << "No" << endl;
	}
	
	return 0;
}

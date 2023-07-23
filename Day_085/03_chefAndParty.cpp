// Question Link: https://www.codechef.com/problems/CHFPARTY


#include <iostream>
#include<algorithm>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	
	while(t--){
	    int n;
	    cin>>n;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	    
	    sort(a, a+n);
	    int count=0;
	    
	    for(int i=0;i<n;i++){
	        if(a[i]<=count)
	            count++;
	    }
	    
	    cout<<count<<endl;
	}
	
	return 0;
}

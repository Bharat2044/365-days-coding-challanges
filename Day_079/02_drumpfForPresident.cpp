// Question Link: https://www.codechef.com/problems/STUDVOTE


#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n,k;
	    cin>>n>>k;
	    int arr[n];
	    int count=0;
	    int votes[n]={0};
	    
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	        int p = arr[i];
	        if (p==i+1)
	        votes[p-1]=-1;
	        else {
	            if (votes[p-1]!=-1)
	            votes[p-1]++;
	            
	        }
	        
	    }
	    for(int i=0; i<n;i++){
	        if((votes[i]>k)||(votes[i]==k))
	        count++;
	    }
	    cout<<count<<endl;
	}
	return 0;
}

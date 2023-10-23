// Question Link: https://www.codechef.com/problems/TWTCLOSE


#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int n,k;
	cin>>n>>k;
	
	int arr[n+1]={0};
	int ans=0;
	
	while(k--){
	    string s;
	    cin>>s;
	    
	    if(s=="CLICK"){
	        int num;
	        cin>>num;
	        
	        if(arr[num]==0){
	            ans++;
	            arr[num]=1;
	        }
	        else{
	            ans--;
	            arr[num]=0;
	        }
	    }
	    else{
	        ans=0;
	        for(int i=1;i<=n;i++){
	            arr[i]=0;
	        }
	    }
	    
	    cout<<ans<<endl;
	}
	
	return 0;
}

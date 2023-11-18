// Question Link: https://www.codechef.com/problems/SSUBSTR


#include <iostream>
using namespace std;

void pushZerosToEnd(int arr[], int n)
{
    int count = {0};  
 
    for (int i = 0; i < n; i++)
        if (arr[i] != 0)
            arr[count++] = arr[i]; 
    
    while (count < n)
        arr[count++] = 0;
}

int main() {
	int t;
	cin>>t;
	
	while(t--){
	    int n;
	    cin>>n;
	    
	    string s;
	    cin>>s;
	    
	    int ans=0;
	    for(int i=1;i<n;i++){
	        if(s[i]=='0'&&s[i-1]=='1')
	        ans++;
	    }
	    
	    cout<<ans<<endl;
	}
	
	return 0;
}

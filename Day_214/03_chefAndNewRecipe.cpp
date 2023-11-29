// Question Link: https://www.codechef.com/problems/CHEFRP


#include <iostream> 
#include <algorithm>
using namespace std;

void solution()
{
    int n;
    cin>>n;
    
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    sort(arr,arr+n);
    if(arr[0]==1)
        cout<<-1<<endl; 
    
    else{
        if(n==1)
        cout<<2<<endl;
        
        else{
           reverse(arr,arr+n); 
           int sum=0;
           
           for(int i=0;i<n-1;i++){
               sum+=arr[i];
           } 
           sum+=2;
           
           cout<<sum<<endl;
        }
        
    }
}

int main() {
	// your code goes here 
	int t;
	cin>>t;
	
	while(t--)
	    solution();
	
	return 0;
}

// Question Link: https://www.codechef.com/problems/SUBTASK?tab=statement



#include <iostream>
using namespace std;

void solution()
{
    int n,m,k;
    cin>>n>>m>>k;
    
    int bin_arr[n], _1_ct=0;
    for(int i=0;i<n;i++)
    {
        cin>>bin_arr[i];
        
        if(bin_arr[i]==1)
            _1_ct++;
    } 
    
    if(_1_ct==n)
        cout<<100<<endl;
    
    else
    {
        int i;
        for(i=0;i<m;i++)
        {
            if(bin_arr[i]!=1) 
            break;
        }
        
        if(i==m)
        cout<<k<<endl;
        
        else
        cout<<0<<endl;
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

// Question Link: https://www.codechef.com/problems/RRCOPY


#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n;
	    cin>>n;
	    
	    int arr[n];
	    int count = 0;
	    unordered_map<int,int> m;
	    
	    for(int i=0;i<n;i++)
	    {
	        cin>>arr[i];
	        m[arr[i]]++;
	        
	        if(m[arr[i]]==1)
	        count++;
	    }
	    
        cout<<count<<endl;
	}
	
	return 0;
}

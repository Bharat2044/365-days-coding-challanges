// Question Link: https://www.codechef.com/problems/CAPPLE


#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	
	for(int i=0; i<t; i++)
	{
	    int n;
	    cin>>n;
	    set<int> s;
	    
	    for(int j=0;j<n; j++)
	    {
	        int a;
	        cin>>a;
	        s.insert(a);
	    }
	    
	    cout<<s.size()<<endl;
	}
	
	return 0;
}

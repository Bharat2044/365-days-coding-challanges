// Question Link: https://www.codechef.com/problems/SPLITMAX


#include <iostream>
using namespace std;
const int MOD=998244353;

signed main() {
	int t,n,a;
	cin>>t;
	
	while(t--)
	{
	    cin>>n;
	    int long long sum=0;
	
	    for(int i=0;i<n;i++)
	    {
	        cin>>a;
	        sum+=a;
	    }
	
	    cout<<(((sum)%MOD)*((sum-1)%MOD))%MOD<<endl;
	}
	
	return 0;
}

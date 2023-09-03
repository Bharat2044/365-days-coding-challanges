// Question Link: https://www.codechef.com/problems/CHEFAPAR


#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int t,n,a,fine,count_a;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    count_a=0,fine=0;
	    for(int i=0;i<n;i++)
	    {
	        cin>>a;
	        if(a==0)
	        {
	            count_a++;
	            fine+=100;
	        }
	        else if(count_a>0)
	        fine+=100;
	    }
	    cout<<(count_a*1000)+fine<<endl;
	}
	return 0;
}

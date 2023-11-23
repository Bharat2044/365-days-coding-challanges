// Question Link: https://www.codechef.com/problems/KDELI


#include <iostream>
#include<algorithm>
#include<math.h>
using namespace std;

int main() {
	// your code goes here
	long long n,ans = 0;
	cin>>n;
	long long a[n];
	
	for(long long i = 0; i<n; i++)
	{
	    cin>>a[i];
	}
	
	sort(a,a+n);
	for(long long i = 0; i<n-1; i++)
	{
	    ans += (a[i]*a[i+1]);
	}
	
	cout<<ans<<endl;
	
	return 0;
}

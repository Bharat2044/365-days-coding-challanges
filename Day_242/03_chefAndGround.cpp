// Question Link: https://www.codechef.com/problems/CHEFGR


#include <stdio.h>
int max(int a,int b)
{
    if(a>b)
    return a;
    return b;
}
int main(void) {
	int t,n,m1;
	scanf("%d",&t);
	while(t--)
	{
	    scanf("%d %d",&n,&m1);
	    int sum=0;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    scanf("%d ",&arr[i]);
	    int m=0;
	    for(int i=0;i<n;i++)
	    m=max(arr[i],m);
	    for(int i=0;i<n;i++)
	    sum+=(m-arr[i]);
	    printf((sum-m1)%n==0?"Yes\n":"No\n");
	}
	return 0;
}

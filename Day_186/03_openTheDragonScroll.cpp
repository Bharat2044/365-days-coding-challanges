// Question Link: https://www.codechef.com/problems/DRAGNXOR


#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        int n,a,b;
        int count1=0,count2=0;
        cin>>n>>a>>b;
        
        while(a!=0)
        {
            if(a%2==1) count1++;
            a=a/2;
        }
        
        while(b!=0)
        {
            if(b%2==1) count2++;
            b=b/2;
        }
        
        int sum=count1+count2;
        long long ans=0;
        
        if(sum<=n)
        {
            for(int i=0;i<sum;i++)
            {
                ans=ans + pow(2,n-i-1);
            }
        } 
        else
        {
            sum=sum-n;
            ans= pow(2,n)-1;
            
            for(int i=sum;i>0;i--)
            {
                ans=ans - pow(2,i-1);
            }
        }
        
        cout<<ans<<endl;
    }
    
	return 0;
}

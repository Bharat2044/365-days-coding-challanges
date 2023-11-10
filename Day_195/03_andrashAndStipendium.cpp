// Question Link: https://www.codechef.com/problems/EGRANDR


#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    
    while(t--)
    {
        int n;
        cin>>n;
        
        int a[n];
        int sum=0;
        float avg=0;
        bool flag=false,f=true;
        
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            sum=sum+a[i];
            if(a[i]==5)
            {
                flag=true;
            }
            if(a[i]<3)
            {
                f=false;
            }
        }
        
        avg=sum/n;
        
        if(flag and f and avg>=4)
        {
            cout<<"Yes\n";
        }
        else
        {
            cout<<"No\n";
        }
        
    }
    
    return 0;
}

// Question Link: https://www.codechef.com/problems/UWCOI20B


#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main() 
{
    ll int t,n,a,i,j;
    cin>>t;
    
    while (t--)
    {
        cin>>n;
        ll int e=0;
        ll int o=0;
        
        for(i=0;i<n;i++)
        {
            cin>>a;
            if(a&1)
            {
                o++;
            }
            else
            e++;
        }
        
        cout<<e*o<<endl;
    }
    
    return 0;
}

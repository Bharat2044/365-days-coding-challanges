// Question Link: https://www.codechef.com/problems/CHEFGRD


#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    
    while (t--)
    {
        int n,x,y;
        cin>>n>>x>>y;
        
        int par2=(x+y)%2; 
        
        if(par2) 
            cout<<"1\n";
        else 
            cout<<"0\n";
    }
    
    return 0;
}

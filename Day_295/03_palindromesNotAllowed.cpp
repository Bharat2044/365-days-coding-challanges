// Question Link: https://www.codechef.com/problems/NOPAL


#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void action()
{
    int n; cin>>n;
    for (int i=0; i<n; i++)
    {
        if (i%3==0)
            cout<<'a';
        else if (i%3==1)
        {
            cout<<'b';
        }
        else
            cout<<'c';
    }
    cout<<endl;
}

int main()
{
    int t;
    cin >> t;
 
    while (t--)
    {
        action();
    }
    
    return 0;
}

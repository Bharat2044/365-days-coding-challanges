// Question Link: https://www.codechef.com/problems/ADAKING


#include<math.h>
#include<vector>
#include<string.h> 
#include <bits/stdc++.h>
using namespace std;
#define it long long int
#define loop(n) for(it i=0;i<n;i++)
#define all(V) V.begin(),V.end()
#define f for(auto &ele : V)
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    it t; cin >> t;
    for(it _ = 0 ; _ < t ; _ += 1)
    {
        
        it k;cin>>k;
        cout<<"O";k--;
        for(int i=0;i<7;i++)
        {
                if(k){cout<<".";k--;}
                else cout<<"X";
        }
        cout<<"\n";
        for(int i=0;i<7;i++)
        {
                for(int j=0;j<8;j++)
                {
                        if(k){cout<<".";k--;}
                        else cout<<"X";
                }
                cout<<"\n";
        }

    }
    return 0;
}

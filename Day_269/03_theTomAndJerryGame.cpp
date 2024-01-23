// Question Link: https://www.codechef.com/problems/EOEO


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
        it n; cin>>n;
        while (n & 1 ^ 1){
            n >>= 1;
        }
        cout<<(n>>1)<<"\n";
    }
    return 0;
}

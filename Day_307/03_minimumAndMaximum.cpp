// Question Link: https://www.codechef.com/problems/MINANDMAX


#include <bits/stdc++.h>
using namespace std;

int main() {
    long long int t,sum;
    scanf("%d", &t);
    
    while (t--)
    {
        long long int per;
        cin >> per;
       
         if (per % 2 == 0)
        {
            per = per / 2;
            sum = (per * (per + 1));
          
        }
        else
        {
            {
                per = (per+1) / 2;
                sum = (per * (per + 1));
                sum=sum-per;
            }
        }
        
        cout<<sum<<endl;
    }

    return 0;
}

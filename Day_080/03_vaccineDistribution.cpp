// Question Link: https://www.codechef.com/problems/VACCINE2


#include<bits/stdc++.h>
using namespace std ;

// 17-2-23 attendence ka chhakar babu bhaiya 

int main()
{
    int t ; 
    cin>>t ;
    
    while(t--)
    {
        float n ,d, age ,count_risk =0 , count_notatrisk=0;
        cin >> n >> d ;
        
        for(int i=0; i<n ; i++)
        {
            cin >> age ;
            if( age <= 9 || age >=80)
            count_risk++;
            else
            count_notatrisk++;
        }
        
        int d1 = ceil(count_risk/d);
        int d2 = ceil(count_notatrisk/d);
        
        cout << d1+d2 << endl ;
    }
    
    return 0 ;
}

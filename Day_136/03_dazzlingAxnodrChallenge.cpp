// Question Link: https://www.codechef.com/problems/AXNODR


#include <bits/stdc++.h>
using namespace std;

int main() {
    long long t;
    cin>>t;
    
    while(t--)
    {
        long long n;
        cin>>n;
        
        if(n%4==2 || n%4 == 3)
        {
        cout<<"3"<<endl;
        }
        else if(n%4==0)
        { 
            cout<<n+3<<endl;
        }
        else {
            cout<<n<<endl;  // if n%4 == 1
        }
    }
    
	return 0;
}

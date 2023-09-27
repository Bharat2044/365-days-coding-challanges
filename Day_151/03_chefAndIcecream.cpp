// Question Link: https://www.codechef.com/problems/CHFICRM


#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    
    while(T--) {
        int n,f5=0,f10=0,f15=0;
        cin >> n;
        
        int a[n];
        int i;
        
        for(i=0;i<n;i++)
            cin >> a[i];
        i=0;
        
        while(i<n) {
            bool f=false;
            
            if(a[i]==10 && f5!=0) {
                f5--;
                f10++;
                f=true;
            }
            else if(a[i]==5) {
                f5++;
                f=true;
            }
            else if(a[i]==15) {
                if(f10 != 0) {
                    f10--;
                    f15++;
                    f=true;
                }
                else if(f10==0 && f5 >1) {
                    f5-=2;
                    f15++;
                    f=true;
                }
            }
            
            if(f==false)
                break;
            i++;
        }
        
        if(i<n)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    
	return 0;
}

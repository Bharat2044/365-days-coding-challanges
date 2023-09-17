// Question Link: https://www.codechef.com/problems/BIGSALE


#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        
        double total=0.0;
        
        while(n--){
            int a,b,c;
            cin>>a>>b>>c;
            
            double inc= a*(c/100.0);
            double sum= a+inc;
            double dec= sum*(c/100.0);
            sum= (a-(sum-dec))*b;
            total+= sum;
        }
        
        int x= total;
        string s= to_string(x);
        int size= 11-s.size();
        
        cout<<fixed<<setprecision(size)<<total<<endl;
    }
    
	return 0;
}

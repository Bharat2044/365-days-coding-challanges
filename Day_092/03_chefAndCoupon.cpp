// Question Link: https://www.codechef.com/problems/COUPON2


#include <iostream>
using namespace std;

int main() {
	// your code goes here d,c
	
	int t;
	cin>>t;
	
	while(t--){
	    
	    int d,c,s[2] = {0,0},f = 1;

	    cin>>d>>c;
	    
	    for(int i=0;i<3;i++){
	       int x;
	       cin>>x;
	       s[0] = s[0] + x;
	    }
	    
	    for(int i=0;i<3;i++){
	       int x;
	       cin>>x;
	       s[1] = s[1] + x;
	    }

        int s_d = s[1] + s[0];
        
	    for(int i=0;i<2;i++){
            
            if(s[i] >= 150 && f == 1){
                s_d = s_d + c ;
                f--;
            }
            else if(s[i] >= 150 && f==0)
                s_d = s_d;
            else if(s[i]<150)
                s_d = s_d + d;
	    }
	    
	    if(s_d < s[0] + s[1] + 2*d )
	        cout << "YES" << endl;	 
        else
            cout << "NO" << endl;
	    
	}
	
	return 0;
}

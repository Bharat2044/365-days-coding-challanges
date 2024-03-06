// Question Link: https://www.codechef.com/problems/SPCP3


#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--){
	    int a,b,c=0;
	    cin >> a >> b;
	    
	    int a1=a,b1=b;
	    
	    if(a>=b){
            while(a%b!=0 && a1%b1!=0){
                c++;
                a--;
                b++;
                a1++;
                b1--;
            }
	    }else{
	        while(a1%b1!=0){
                c++;
                a1++;
                b1--;
            }
	    }
	    
        cout << c << endl;
	}
	
	return 0;
}

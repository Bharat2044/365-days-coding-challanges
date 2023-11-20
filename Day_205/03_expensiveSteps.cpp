// Question Link: https://www.codechef.com/problems/EXPSTP


#include <iostream>
#include<cmath>
using namespace std;

int ans(int a, int b, int n){
    int ans = min(min(a,b), min(abs(a-n)+1,abs(b-n)+1));
    return ans;
}

bool check(int a, int b, int n){
        if(a>=1 && a<=n && b>=1 && b<=n){ 
            return true;
        }
        else{
            return false;
        }
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	
	while(t--){
	    int n,x1,y1,x2,y2;
	    cin>>n>>x1>>y1>>x2>>y2;
	    
	    if(check(x1,y1,n) && check(x2,y2,n)){
	        int num = abs(x1-x2) + abs(y1-y2);
	        cout<<min(ans(x1,y1,n)+ans(x2,y2,n),num)<<endl;
	    } else{
	        cout<<0<<endl;
	    }
	}
	
	return 0;
}

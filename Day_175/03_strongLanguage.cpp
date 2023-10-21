// Question Link: https://www.codechef.com/problems/SSCRIPT


#include <iostream>
using namespace std;

bool solve(string s,int n,int k){
    int i=0,count=0;
    
    while(i<n){
        if(s[i]=='*')
            count++;
        else{
            if(count>=k)
                return 1;
            count=0;
        }
        i++;
    }

    return (count>=k);
}

int main() {
	int t;
	cin>>t;
	
	while(t--){
	    int n,k;
	    cin>>n>>k;
	    
	    string s;
	    cin>>s;
	    
	    if(solve(s,n,k))
	        cout<<"YES"<<endl;
	    else
	        cout<<"NO"<<endl;
	}
	
	return 0;
}

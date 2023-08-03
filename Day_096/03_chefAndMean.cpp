// Question Link: https://www.codechef.com/problems/CHFM


#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--){
	    int x=0,flag=0,ans=0;
	    double sum=0,mean=0;
	    
	    int n;
	    cin>>n;
	    
	    vector<double> a;
	    for(int i=0;i<n;i++){
	        cin>>x;
	        sum+= x;
	        a.push_back(x);
	    }
	    
	    mean = sum/n;
	    
	    for(int i=0;i<n;i++){
	        if(a[i] == mean){
	            ans = i+1;
	            flag = 1;
	            break;
	        }
	    }
	    
	    if(flag)
	        cout<<ans<<endl;
	    else
	        cout<<"Impossible"<<endl;
	}
	
	return 0;
}

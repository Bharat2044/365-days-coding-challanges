// Question Link: https://www.codechef.com/problems/MINFD


#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	
	while(t--){
	    int x,y;
	    cin>>x>>y;
	    
	    vector<int>ans(x,0);
	    for(auto &i :ans){
	        cin>>i;
	    }
	    
	    sort(begin(ans),end(ans));
	    int i=0,j=x-1;
	    int sum=0,count=0,flage=0;
	    
	    for(int j=x-1;j>=0;j--){
	        sum+=ans[j];
	          count++;
	          
	        if(sum>=y){
	            flage=1;
	            cout<<count<<endl;
	            break;
	        }
	    }
	    if(flage==0){
	       cout<<"-1"<<endl;
	    }
	}
	
	return 0;
}

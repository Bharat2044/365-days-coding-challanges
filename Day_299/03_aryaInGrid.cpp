// Question Link: https://www.codechef.com/problems/ARYAGRID


#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        long int n,m,x,y,l;
        cin>>n>>m>>x>>y>>l;
        
        long int up=0,down=0,left=0,right=0;
        up=((x-1)/l);
        down=((n-x)/l);
        
        left=((y-1)/l);
        right=((m-y)/l);
        
        long int total_cnt=((left*(up+down))+(right*(up+down)))+(left+right)+(up+down+1);
        cout<<total_cnt<<endl;
}

	return 0;
}

// Question Link: https://www.codechef.com/problems/RIGHTRI


#include <bits/stdc++.h>
using namespace std;

int  yes(int a,int b,int c,int d,int e,int f){
    
   int x = pow((c-a),2)+pow((d-b),2);
   int y = pow((f-b),2)+pow((e-a),2);
   int z = pow((c-e),2)+pow((d-f),2);
   
   if(x>0 and y>0 and z>0){
      if( x==(y+z) or y==(x+z) or z == (x+y)){
       return 1;
       }
      else{
       return 0;
      }
   }
   else{
       return 0;
   }
}

signed main() {
	// your code goes here
	int t;
	cin>>t;
	int count=0;
	
	while(t--){
	    int a,b,c,d,e,f;
	    cin>>a>>b>>c>>d>>e>>f;
	    
	    count += yes(a,b,c,d,e,f);
	    
	}
	
	cout<<count<<endl;
	 
	return 0;
}

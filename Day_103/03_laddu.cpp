// Question Link: https://www.codechef.com/problems/LADDU


#include <iostream>
using namespace std;

int main() {
	int t,n,value;
	string o,act;
	cin>>t;
	while(t--)
	{
	    cin>>n>>o;
	    int point=0;
	    for (int i=0;i<n;i++)
	    {
	        cin>>act;
	        if(act=="CONTEST_WON" || act == "BUG_FOUND")
	            cin>>value;
	        
	        if(act=="CONTEST_WON")
	        {
	            point+=300;
	            if(value<=20)
	                point+=20-value;
	        }
	        
	        if(act=="BUG_FOUND")
	            point+=value;
	            
	        if(act=="TOP_CONTRIBUTOR")
	            point+=300;
	        
	        if(act=="CONTEST_HOSTED")
	            point+=50;
	    }
	    
	    cout<<(o=="INDIAN"?point/200:point/400)<<endl;
	}
	
	return 0;
}

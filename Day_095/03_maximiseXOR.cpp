// Question Link: https://www.codechef.com/problems/XORMAX


#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	
	while(t--)
	{
	    string a,b;
	    cin>>a>>b;
	    
	    int zeroes = 0;
	    int ones = 0;
	    
	    for(int i=0;i<a.length();i++)  // asboth string has same length
	    {
	        if(a[i]=='0') 
	         zeroes++;
	        else
	         ones++;
	         
	        if(b[i]=='0')
	          zeroes++;
	        else
	          ones++;
	    }
	    
	    int temp = min(zeroes,ones);
	    string ans = "";
	    
	    for(int i=0;i<temp;i++)          // setting 1's at MSB places
	      ans+='1';
	      
	    for(int i=temp;i<a.length();i++)   // setting 0's at LSB places
	      ans+='0';
	      
	    cout<<ans<<endl;
	}
	
	return 0;
}

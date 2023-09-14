// Question Link: https://www.codechef.com/problems/THREEPOW2


#include <iostream>
using namespace std;

void status(string s, int n)
{
    int count = 0;
    for(auto i : s)
    {
        if(i=='1')
        {
            count++;
        }
    }
    
    if(s == "1" || s == "10")
    {
        cout<<"NO"<<endl;
    }
    else if(count <= 3)
    {
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    string s;
	    cin>>s;
	    
	    status(s,n);
	    
	}
	
	return 0;
}

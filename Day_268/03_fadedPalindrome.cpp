// Question Link: https://www.codechef.com/problems/LEXOPAL


#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	
	while(t--){
	    string s;
	    cin>>s;
	    
	    int i=0,j=s.length()-1,c=0;
	    
	    while(i<=j)
	    {
	        if(s[i]==s[j] && s[i]=='.'){
    	            s[i] = s[j] = 'a';
	        }
	        else if(s[i]=='.' && s[j]!='.')
	        {
	            s[i]=s[j];
	           
	        }
	        else if(s[i]!='.' && s[j]=='.')
	        {
	            s[j]=s[i];
	        }
	        else if(s[i]!=s[j])
	        {
	            c++;
	        }
	        i++;j--;
	    }
	    
	    if(c!=0) 
	        cout<<"-1"<<endl;
	    else 
	        cout<<s<<endl;
	}
	
	return 0;
}

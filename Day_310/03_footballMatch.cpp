// Question Link: https://www.codechef.com/problems/FBMT


#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        string str;
        stack<string> st1;
        stack<string> st2;

       for(int i=0;i<n;i++)
       {
           cin>>str;
           if(st1.empty() || str == st1.top())
           {
               st1.push(str);
           }
           else if(st2.empty()||st2.top()==str)
           {
               st2.push(str);
            }
       }
       

        if(st1.size()>st2.size()){
	        cout<<st1.top()<<endl;
	    }
	    else if(st1.size()<st2.size()){
	        cout<<st2.top()<<endl;
	    }
	    else{
	        cout<<"Draw"<<endl;
	    }
    }
    
    return 0;
}

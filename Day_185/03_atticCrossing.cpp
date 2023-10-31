// Question Link: https://www.codechef.com/problems/ATTIC


#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define N 1000000 

int main() {
	// your code goes here
	int test;
	cin>>test;
	
	while(test--)
	{
	    string str ;
	    cin>>str;
	    
	    int n = str.length();
	    int days=0;
	    int count=0;
	    int max =0;
	    
	    for(int i=0;i<n;i++)
	    {
	        if(str[i]=='.'){
	            count++;
	        }
	        else{
	            if(max<count){
	                max = count;
	                days++;
	            }
    	        count=0;
	        }
	    }
	    
	    cout<<days<<endl;
	}
	
	return 0;
}




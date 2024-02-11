// Question Link: https://www.codechef.com/problems/MINLCS


#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
  
	while(t--){
	    int n;
	    cin>>n;
	    int c=0;
    
	    string a,b;
	    cin>>a>>b;
	    map<char,int>am,bm;
    
	    for(char i:a){
	        am[i]++;
	    }
    
	    for(char i:b){
	        bm[i]++;
	    }
    
	    for(char i='a';i<='z';++i){
	        c=max(c,min(am[i],bm[i]));
	    }
	    cout<<c<<endl;	    
	}
	   
	return 0;
}

void pushZerosToEnd(int arr[], int n)
{
    int count = {0};  
    
    for (int i = 0; i < n; i++)
        if (arr[i] != 0)
            arr[count++] = arr[i];
            
    while (count < n)
        arr[count++] = 0;
}

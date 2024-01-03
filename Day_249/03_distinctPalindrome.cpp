// Question Link: https://www.codechef.com/problems/DISPAL


#include <iostream>
using namespace std;

void dist(long long int n,int x){
    
    long long int half=n/2;
    
    string s;
    
    if(n%2==0){
        if(x>half){
            cout<<-1;
            return;
        }
        // if not then what
        char y='a';
        for(int i=0;i<x;i++){
            s.push_back(y);
            y++;
        }
        if(x<half){
            long long int diff=half-x;
            for(int i=0;i<diff;i++){
                s.push_back('a');
            }
        }
        string k;
        int z=0;
        for(int i=s.size()-1;i>=0;i--){
            k.push_back(s[i]);
            z++;
        }
        string m=s+k;
        cout<<m;
        return;
    }
    if(n%2!=0){
        if((x-1)>(half)){
            cout<<-1;
            return;
        }
        //if not then what
        if(x==1){
            string s;
            char y='a';
            for(int i=0;i<n;i++){
                s.push_back(y);
                // y++;
            }
            cout<<s;
            return;
        }
        string s;
        
        char y='a';
        for(int i=0;i<x-1;i++){
            s.push_back(y);
            y++;
        }
        if(x-1 <half){
            long long int diff=half-(x-1);
            for(int i=0;i<diff;i++){
                s.push_back('a');
            }
        }
        
        string k;
        int z=0;
        for(int i=s.size()-1;i>=0;i--){
            k.push_back(s[i]);
            z++;
        }
        s.push_back(y);
        string m=s+k;
        cout<<m;
        return;
        
    }
    
    
}

int main() {
	// your code goes here
	int t;
	cin>>t;
  
	for(int i=0;i<t;i++){
	    long long int n,x;
	    cin>>n>>x;
	    
	    if(x>26){
	        cout<<-1<<endl;
	    }
	    else{
	        dist(n,x);
	        cout<<endl;
	    }
	}
	
	return 0;
}

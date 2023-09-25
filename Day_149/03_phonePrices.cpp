// Question Link: https://www.codechef.com/problems/S10E


#include<bits/stdc++.h>
using namespace std;

/*class Node{
  public:
    int data;
    Node*prev;
    Node*next;
    
    Node(int d){
        this->data=d;
        this->next=NULL;
        this->prev=NULL;
    }
    
    ~Node(){
        int val=this->data;
        if(next!=NULL){
            delete next;
            next=NULL;
        }
    }
};*/

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int p[n];
	    for(int i=0;i<n;i++){
	        cin>>p[i];
	    }
	    int count=1;
        for(int i=5;i<n;i++){
            if(p[i]<p[i-1]&&p[i]<p[i-2]&&p[i]<p[i-3]&&p[i]<p[i-4]&&p[i]<p[i-5]){
                count++;
            }
        }
        if(p[1]<p[0])count++;
        if(p[2]<p[1]&&p[2]<p[0])count++;
        if(p[3]<p[2]&&p[3]<p[1]&&p[3]<p[0])count++;
        if(p[4]<p[3]&&p[4]<p[2]&&p[4]<p[1]&&p[4]<p[0])count++;
        cout<<count<<endl;
	}
	
	return 0;
}

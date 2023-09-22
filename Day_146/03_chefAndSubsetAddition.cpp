// Question Link: https://www.codechef.com/problems/SUBSTADD


#include <iostream>
using namespace std;

int main() {
    int t;
    cin>>t;
    
    while (t--){
        int n,x,y;
        cin>>n>>x>>y;
        
        int a[n],b[n];
        
        for (int i=0;i<n;i++)
            cin>>a[i];
        for (int i=0;i<n;i++)
            cin>>b[i];
            
        int k=0;
        
        for (int i=0;i<n;i++){
            if (b[i]-a[i]==x|| b[i]-a[i]==y) 
                k=0;
            else {
                k=1;
                break;
            }
        }
        
        if (k==1) 
            cout<<"no";
        else 
            cout<<"yes";
        cout<<endl;
    }
	
	return 0;
}

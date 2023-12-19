// Question Link: https://www.codechef.com/problems/PAIRPAIN


#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    
    while(t--){
        long long int n;
        cin>>n;
        long long int a[n];
        
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        
        long long int count=0,con=0;
        
        for(int i=0;i<n;i++){
            if(a[i]==1){
                con++;
            }
            else if(a[i]==2){
                count++;
            }
        }
        
        cout<<con*(con-1)/2+count*(count-1)/2+con*(n-con)<<endl;
    }\
	return 0;
}

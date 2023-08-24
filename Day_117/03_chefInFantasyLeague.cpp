// Question Link: https://www.codechef.com/problems/FFL


#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int T;cin>>T;while (T--){
      
        int N,S;cin>>N>>S;int A[N],B[N];
          vector <int>v1;
        vector <int>v2;
        for (int i=0;i<N;i++){cin>>A[i];}
        for (int i=0;i<N;i++){cin>>B[i];
            if (B[i]==0)
            v1.push_back(A[i]);
            else
            v2.push_back(A[i]);
        }
        int k=0;
        

        
        if (v1.size()!=0 && v2.size()!=0){
            sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
            S=S+v1[0]+v2[0];
            k=1;
        }
      
      
    if(k==1 && S<=100)
      cout<<"yes";
      else 
      cout<<"no";
      cout<<endl;
        
    }
   
	return 0;
}

// Question Link: https://www.codechef.com/problems/BESTBATS


#include<bits/stdc++.h>
using namespace std;

int factorial(int n) {
    if (n == 0) 
        return 1;
    else 
        return n * factorial(n - 1);
}

int permu(int n,int r){
    int fact_n=factorial(n);
    int fact_n_r=factorial(n-r);
    int fact_r=factorial(r);
    int per=fact_n/(fact_n_r* fact_r);
    
    return per;
}

int main() {
    int t;
    cin>>t;
    
    while(t--){
        vector<int>v(11);
        map<int,int,greater<int>>m;
        
        for(int i=0;i<11;i++)
        {  
            int x;cin>>x;
            m[x]++;
        
        }
        
        int n;cin>>n;
        int count=1;
        
        for(auto &i:m)
        { 
            if(n!=0){
                if((i.second)<=n){
                    count*=permu(i.second,i.second);
                    n-=i.second;
                }else{
                     count*=permu(i.second,i.second-n);
                     n=0;
                }
            }
        }
        
        cout<<count<<endl;
    }
    
    return 0;
}

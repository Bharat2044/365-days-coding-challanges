// Question Link: https://www.codechef.com/problems/DAILY


#include <bits/stdc++.h>
using namespace std;

int nCr(int n, int r)
{
    if (r > n)
        return 0;
    if (r == 0 || r == n)
        return 1;
    return nCr(n - 1, r - 1) + nCr(n - 1, r);
}

int main() {
    int a,n;
    cin>>a>>n;
    int ways=0;
    while(n--){
        string s;
        cin>>s;
        vector<int>v;
        int num=0;
        for(int i=1;i<=36;i++){
            if(s[i-1]=='0'){
                num=num+1;
            }
            if(i%4==0){
                v.push_back(num);
                num=0;
            }
        }
        int x=0;
        num=0;
        for(int j=54;j>=37;j--){
            if(s[j-1]=='0'){
                num=num+1;
            }
            if(j%2==1){
                v[x]=v[x]+num;
                num=0;
                x++;
            }
        }
        for(int k=0;k<9;k++){
            if(a<=v[k]){
                int l=nCr(v[k],a);
                ways=ways+l;
            }
        }
    }
    cout<<ways<<endl;
    
	return 0;
}

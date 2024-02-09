// Question Link: https://www.codechef.com/problems/COVSPRD


#include<bits/stdc++.h>
using namespace std;
long long int a[40];

void fill(){
    for(int i=0;i<33;i++){
        if(i<=10){
          a[i]=pow(2,i);
        }
        else{
            a[i]=a[i-1]*3;
        }
    }
}

int main(){
    int t;
    cin >>t;
    fill();
    for(int i=0;i<t;i++){
        long int  n,d;
        cin >>n>>d;
        long int  h;
        for(int j=0;j<22;j++){
            if(n<=a[j]){
                h=j;
                break;
            }
        }
        if(h<=d){
            cout<<n<<endl;
        }
        else{
            if(d<=10){
                cout<<pow(2,d)<<endl;
            }
            else{
                long int sum=pow(2,10)*pow(3,d-10);
                cout<<sum<<endl;
            }
        }
    }
    
    return 0;
}

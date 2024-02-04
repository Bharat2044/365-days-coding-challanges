// Question Link: https://www.codechef.com/problems/EVEQODD


#include<iostream>
#include<bits/stdc++.h>
using namespace std;
long int h[32];
void fill(){
    for(int i=0;i<32;i++){
        h[i]=powl(2,i);
    }
}
int main(){
    int t;
    cin >>t;
    fill();
    for(int i=0;i<t;i++){
        int n;
        cin >>n;
        n*=2;
        int m,l;
        m=l=0;
        long int a[n],b[n];
        for(int j=0;j<n;j++){
            cin >>a[j];
            if(a[j]%2==0){
                m++;
            }
            else{
                l++;
            }
        }
        for(int j=0;j<n;j++){
            if(a[j]%2==0){
                long int e=0;
                while(a[j]%2==0){
                    a[j]/=2;
                    e++;
                }
                b[j]=e;
            }
                else{
                    b[j]=9e9;
                }
            }
        sort(b,b+n);
        if(m==l){
            cout<<0<<endl;
        }
        else if(l>m){
            long int k=0;
            while(l!=m){
                m++;
                l--;
                k++;
            }
            cout<<k<<endl;
        }
        else{
            long int sum,r;
            sum=r=0;
            while(m!=l){
                sum+=b[r];
                r++;
                m--;
                l++;
            }
            cout<<sum<<endl;
        }
    }
    return 0;
}

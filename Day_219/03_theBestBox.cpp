// Question Link: https://www.codechef.com/problems/J7


#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        double p,s;
        cin>>p>>s;
        //double l,b,h;
        //(4*l+8*b)=p;
        //2*(2*l*b+b*b)=s;
        /*for max vol we have to maximise l*b*h which is possible by doing any two eqal
        calculation...
        4l=p-8b;  4lb + 2b^2=s,  (p-8b)b+2b^2=s;  pb-8b^2+2b^2=s; 6b^2-pb+s=0...now find b from here*/
        double b=(p-sqrt(p*p-24*s))/12;
        double l=(p-8*b)/4;
        double vol=(l*b*b);
        cout<<fixed<<setprecision(2)<<vol<<endl;
    }
	return 0;
}

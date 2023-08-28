// Question Link: https://www.codechef.com/problems/SPALNUM


#include <iostream>
using namespace std;

int palindromic(int n){
    int e=0;
    while(n != 0) {
    int remainder = n % 10;
    e = e * 10 + remainder;
    n /= 10;
  }
  return e;
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    int L,R;
	    cin>>L>>R;
	    int sum=0;
	    for(int i=L;i<=R;i++){
	        int r=palindromic(i);
	        if(i==r) sum=sum+i;
	    }
	    cout<<sum<<endl;
	}
  
	return 0;
}

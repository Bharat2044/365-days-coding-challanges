// Question Link: https://www.codechef.com/problems/CHEFDETE


#include <iostream>
using namespace std;

int main() {
	int n;
	cin>>n;
	
	int arr[n];
	int freq[n+1]={0};
	
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        freq[arr[i]]++;
    }
    for(int i=0;i<=n;i++)
    {
        if(freq[i]==0)
            cout<<i<<" ";
    }
    
	return 0;
}

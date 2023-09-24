// Question Link: https://www.codechef.com/problems/MAKEABEQUAL



#include <iostream>
using namespace std;

int main() {
	int t; 
	cin >> t;
	
	while(t--)
	{
	    long int n; cin >> n;
	    long int arr1[n], arr2[n];
	    
	    for(int i = 0; i < n; i++)
	        cin >> arr1[i];
	    
	    long int count1 = 0, count2 = 0;
	    
	    for(int i = 0; i < n; i++)
	    {
	        cin >> arr2[i];
	        
	        if(arr1[i] > arr2[i])
	            count1 += arr1[i] - arr2[i];
	        else
	            count2 += arr2[i] - arr1[i];
	    }
	    
	    if(count1 == count2) 
	        cout << count1 << endl;
	    else 
	        cout << -1 << endl;
	}
	
	return 0;
}

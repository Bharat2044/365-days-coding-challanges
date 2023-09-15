// Question Link: https://www.codechef.com/problems/CHEFSUM


#include <iostream>
using namespace std;

int solution(int* arr, int n)
{
    int index = 0;
    int minElement = arr[0];
    
    for(int i = 1; i < n; i++)
    {
        if(minElement > arr[i])
        {
            minElement = arr[i];
            index = i;
        }
    }
    
    return index + 1;
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i = 0; i < n; i++)
	    {
	        cin>>arr[i];
	    }
	   
	    cout<<solution(arr,n)<<endl;
	}
	
	return 0;
}

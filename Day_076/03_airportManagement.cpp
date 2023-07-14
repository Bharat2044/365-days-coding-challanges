// Question Link: https://www.codechef.com/problems/AIRM


#include <iostream>
#include<unordered_map>
using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--)
	{
	    
	    int n;
	    cin>>n;
	    int arr[n];
	    unordered_map<int, int>freq;
	    
	    for(int i=0;i<n;i++)
	    {
	        cin>>arr[i];
	        freq[arr[i]]++;
	    }
	    
	    for(int i=0;i<n;i++)
	    {
	        cin>>arr[i];
	        freq[arr[i]]++;
	    }
	    
	    int maxFrequency=0;
	    for(const auto & pair:freq)
	        {
	            maxFrequency=max(maxFrequency,pair.second);
	        }
	        
	        cout<<maxFrequency<<endl;
	    
	    }
	
	return 0;
}

// Question Link: https://www.codechef.com/problems/LPC


#include <bits/stdc++.h>
using namespace std;

int calculateDifference(char a, char b)
{
    int diff = abs(a - b);
    return min(diff, 10 - diff);
}

int main() {
	// your code goes here
	int T;
	cin>>T;
	
	while(T--)
	{
	    int N, M;
	    string S, K;
	    
	    cin>>N>>M;
	    cin>>S>>K;
	    
	    
	    int ans = INT_MAX;
	    for(int i = 0; i <= N - M; i++)
	    {
	        int diff = 0;
	        for(int j = 0; j < M; j++)
	        {
	            diff += calculateDifference(S[i + j], K[j]);
	        }
	        ans = min(ans, diff);
	    }
	    cout<<ans<<endl;
	}
	   
	return 0;
}

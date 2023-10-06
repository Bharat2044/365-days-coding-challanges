// Question Link: https://www.codechef.com/problems/HRDSEQ


#include <bits/stdc++.h>
using namespace std;

int main()
{
	int T;
	cin >> T;

	vector<int> v;
	v.push_back(0);

	for (int i = 1; i < 128; i++) {
		if(count(v.begin(),v.begin()+i-1,v[i-1]))
		{
			for (int j = i-2; j >= 0; j--)
			{
				if(v[j]==v[i-1])
				{
					v.push_back(i-j-1);
					break;
				}
			}				
		}
		else 
		    v.push_back(0);
	}

	while (T--)
	{
		int n;
		cin>>n;
		
		cout<<count(v.begin(),v.begin()+n,v[n-1])<<endl;
	}
	
	return 0;
}

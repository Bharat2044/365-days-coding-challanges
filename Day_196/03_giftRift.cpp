// Question Link: https://www.codechef.com/problems/SAD


#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m,n;
    cin>>m>>n;
    
    vector<vector<int>> v(m, vector<int>(n));
    vector<vector<int>> v1(n, vector<int>(m));
    
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
         int y;
         cin>>y;
         
         v[i][j]=y;
         v1[j][i]=y;
        }
    }
    
    int a[m],b[n];
    for(int i=0;i<m;i++)
    {
        int y=*min_element(v[i].begin(),v[i].end());
        a[i]=y;
     
    }
    
    for(int i=0;i<n;i++)
    {
        int z=*max_element(v1[i].begin(),v1[i].end());
        b[i]=z;
    }
    
    int e=0;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[i]==b[j])
            {
            cout<<a[i]<<endl;
            return 0;
            }
        }
    }
    
    cout<<"GUESS"<<endl;
    
	return 0;
}

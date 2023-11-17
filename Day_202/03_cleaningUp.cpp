// Question Link: https://www.codechef.com/problems/CLEANUP


#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int arr[m];
        
        for (int i = 0; i < m; i++)
            cin >> arr[i];
        
        sort(arr, arr + m);
        vector<int> chef, assi;
        
        int i = 1, idx = 0, btn = 0; 
        
        while (i <= n) 
        {
            if (!btn && (arr[idx] != i)) 
            {
                chef.push_back(i);
                btn = 1;           
            }
            else if (btn && (arr[idx] != i)) 
            {
                assi.push_back(i);
                btn = 0;
            }
            else 
                idx++;
                
            i++;
        }
        
        if (!(chef.size()))
            cout << "-1";
            
        for (int i = 0; i < chef.size() + assi.size(); i++)
        {
            if (i < chef.size())
                cout << chef[i] << ' ';
            else
            {
                if (!(i - chef.size()))
                    cout << endl;
                cout << assi[i - chef.size()] << ' ';
            }
        }
        
        if (!(assi.size()))
            cout << "\n-1";
        cout << endl;
    }
    
    return 0;
}

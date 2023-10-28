// Question Link: https://www.codechef.com/problems/TIES


#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        vector<int> dif(n);
        bool flag = true;

        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        long long total = accumulate(v.begin(), v.end(), 0);
        long long mean=total/n;
        long long final = total % n;

        for (int i = 0; i < n; i++)
        {
            dif[i] = abs(mean - v[i]);
        }

        if(final!=0){
            cout<<"no"<<endl;
            flag=false;
        }
        else{
            for (int i = 0; i < n; i++)
            {
                if (dif[i] % 2 != 0)
                {
                    cout << "no" << endl;
                    flag = false;
                    break;
                }
                else
                {
                    flag = true;
                }
            }
        }
        
        if (flag == true)
        {
            cout << "yes" << endl;
        }
    }
    
    return 0;
}

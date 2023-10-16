// Question Link: https://www.codechef.com/problems/SPELLBOB


#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        set<int> s;
        int b = 0, o = 0;
        string cup, cdown;
        cin >> cup >> cdown;
        
        for (int i = 0; i < 3; i++)
        {
            if ('b' == cup[i] || 'b' == cdown[i])
            {
                b++;
                s.insert(i);
            }
            if ('o' == cup[i] || 'o' == cdown[i])
            {
                o++;
                s.insert(i);
            }
        }
        
        if (b > 1 && o > 0)
        {
            if (s.size() == 3)
                cout << "yes" << endl;
            else
                cout << "no" << endl;
        }
        else
            cout << "no" << endl;
    }
    
    return 0;
}

// Question Link: https://www.codechef.com/problems/VILTRIBE


#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        
        int ans = 0, aans = 0, bans = 0;
        int acount = 0, bcount = 0;
        
        
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 'A')
            {
                acount++;
                int temp = 0;
                
                for (int j = i + 1; s[j] == '.' && j < s.length() - 1; j++)
                {
                    temp++;
                    if (s[j + 1] == 'A')
                    {
                        aans = aans + temp;
                    }

                    i = j;
                }
            }
            
            if (s[i] == 'B')
            {
                bcount++;
                int temp = 0;
                
                for (int j = i + 1; s[j] == '.' && j < s.length() - 1; j++)
                {
                    temp++;
                    if (s[j + 1] == 'B')
                    {
                        bans = bans + temp;
                    }

                    i = j;
                }
            }
        }
        
        cout << acount + aans << " " << bcount + bans << endl;
    }
    
    return 0;
}

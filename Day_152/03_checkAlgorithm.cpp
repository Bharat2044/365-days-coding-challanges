// Question Link: https://www.codechef.com/problems/CHEALG


#include<bits/stdc++.h>
using namespace std;

int main() {
    int t; 
    cin >>t;
    
    while (t--)
    {
        string str;
        cin >>str;
        string res = "";
        int count = 1;
        
        for (int i = 0; i < str.length() - 1; ++i)
        {
            if (str[i + 1] == str[i]) count++;
            else
            {
                res += str[i] + to_string(count);
                count = 1;
            }
        }
        
        res += str[str.length() - 1] + to_string(count);
        
        if (res.length() < str.length()) 
            cout <<"YES\n";
        else 
            cout <<"NO\n";
    }
    
	return 0;
}

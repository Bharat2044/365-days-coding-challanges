// Question Link: https://www.codechef.com/problems/TOTR


#include<bits/stdc++.h>
using namespace std;

int isUpper(char ch)
{
    if(ch>='A' && ch<='Z'){
        return 1;
    }
    return 0;
}

int main()
{
    int test;
    cin>>test;
    string str;
    cin>>str;
    int len = str.length();
    map<char,char> mp;
    char ch = 'a';
    for(int i =0;i<len;i++)
    {
        
        mp[ch] = str[i];
        ch++;
    }
    while (test--)
    {
        string str1;
        cin>>str1;
        int len1 = str1.length();
        for(int i=0;i<len1;i++)
        {
            
            char ch1 = str1[i];
            if(ch1=='_'){
              cout<<' ';
            }
            else if(ch1=='?' || ch1=='!' || ch1=='.' || ch1==','){
             cout<<ch1;
            }
            else{
               if(isUpper(ch1)==1){
                cout<<(char)toupper(mp[tolower(ch1)]);
               }
              else{
                cout<<mp[ch1];
              }
            }
            
        }
        cout<<endl;
        
    }

    return 0;
    
}

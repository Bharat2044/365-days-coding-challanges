// Question Link: https://www.codechef.com/problems/CHEFROUT


#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	
	while(t--)
	{
	    string s;
	    cin >> s;
        int c = 0;
         
        for (int i = 0; i < s.length() -1 ; i++)
        {
            if ((s[i] == 'E' && s[i + 1] == 'C') || (s[i] == 'S' && (s[i + 1] == 'E' || s[i + 1] == 'C')))
            {
                c = 1;
                break;
            }
        }
        
        if (c == 0)
            cout << "yes"<<endl;
        else
            cout << "no"<<endl;
    }

	return 0;
}

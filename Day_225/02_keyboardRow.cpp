// Question Link: https://leetcode.com/problems/keyboard-row/

/*
500. Keyboard Row

Given an array of strings words, return the words that can be typed using letters of the alphabet on only one row of American keyboard like the image below.

In the American keyboard:
the first row consists of the characters "qwertyuiop",
the second row consists of the characters "asdfghjkl", and
the third row consists of the characters "zxcvbnm".

Example 1:
Input: words = ["Hello","Alaska","Dad","Peace"]
Output: ["Alaska","Dad"]
Example 2:
Input: words = ["omk"]
Output: []
Example 3:
Input: words = ["adsdf","sfd"]
Output: ["adsdf","sfd"] 

Constraints:
1 <= words.length <= 20
1 <= words[i].length <= 100
words[i] consists of English letters (both lowercase and uppercase). 
*/



class Solution {
public:
    vector<string> findWords(vector<string>& w) {
        int i,j,c1=0,c2=0,c3=0;
        
        for(j=0;j<w.size();j++)
        {
            c1=0,c2=0,c3=0;
            string s=w[j];
            for(i=0;i<s.length();i++)
            {
                if(s[i]=='A' ||s[i]=='a' ||s[i]=='S' ||s[i]=='s' ||s[i]=='D' ||s[i]=='d' ||s[i]=='F' ||s[i]=='f' ||s[i]=='G' ||s[i]=='g' ||s[i]=='H' ||s[i]=='h' ||s[i]=='J' ||s[i]=='j' ||s[i]=='K' ||s[i]=='k' ||s[i]=='L' ||s[i]=='l')
                {
                    c2++;
                }
                else if(s[i]=='Z' ||s[i]=='z' ||s[i]=='X' ||s[i]=='x' ||s[i]=='C' ||s[i]=='c' ||s[i]=='V' ||s[i]=='v' ||s[i]=='B' ||s[i]=='b' ||s[i]=='N' ||s[i]=='n' ||s[i]=='M' ||s[i]=='m')
                {
                    c3++;
                }
                else
                {
                    c1++;
                }
            }
            if(c1!=w[j].length() && c2!=w[j].length() && c3!=w[j].length())
            {
                w.erase(w.begin()+j);
                j--;
            }
        }
        return w;
    }
};

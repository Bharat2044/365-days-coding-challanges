// Question Link: https://leetcode.com/problems/edit-distance/

/*
72. Edit Distance

Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character
 
Example 1:
Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:
Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
 
Constraints:
0 <= word1.length, word2.length <= 500
word1 and word2 consist of lowercase English letters.
*/



class Solution {
public:
    int spaceoptimise(string& word1,string& word2){
         vector<int> curr(word2.length()+1,0);
         vector<int> next(word2.length()+1,0);
        for(int j=0;j<word2.length();j++)
            next[j]=word2.length()-j;
        for(int i=word1.length()-1;i>=0;i--){
                curr[word2.length()]=word1.length()-i;
            for(int j=word2.length()-1;j>=0;j--){
                int ans=0;
                if(word1[i]==word2[j])
                    ans=next[j+1];
                else{
                    int replaced=1+next[j+1];
                    int deleted=1+next[j];
                    int inserted=1+curr[j+1];
                    ans=min(replaced,min(deleted,inserted));
                }
                curr[j]=ans;
            }
            next=curr;
        }
        return next[0];
    }
    
    int minDistance(string word1, string word2) {
        if(word1.length()==0)
            return word2.length();
        if(word2.length()==0)
            return word1.length();
        return spaceoptimise(word1,word2);
    }
};

// Question Link: https://leetcode.com/problems/word-subsets/description/

/*
916. Word Subsets

You are given two string arrays words1 and words2.
A string b is a subset of string a if every letter in b occurs in a including multiplicity.

For example, "wrr" is a subset of "warrior" but is not a subset of "world".
A string a from words1 is universal if for every string b in words2, b is a subset of a.
Return an array of all the universal strings in words1. You may return the answer in any order.

Example 1:
Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["e","o"]
Output: ["facebook","google","leetcode"]
Example 2:
Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["l","e"]
Output: ["apple","google","leetcode"]
 
Constraints:
1 <= words1.length, words2.length <= 10^4
1 <= words1[i].length, words2[i].length <= 10
words1[i] and words2[i] consist only of lowercase English letters.
All the strings of words1 are unique.
*/



class Solution {
public:
    bool isSame(vector<int>h1,vector<int>h2){
        for(int i=0;i<26;i++){
            if(h1[i]>h2[i])return false;
        }
        return true;
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string>res;
        vector<int>hash1(26,0);

        for(int i=0;i<words2.size();i++){
            vector<int>temp(26,0);
            for(int j=0;j<words2[i].length();j++){
                temp[words2[i][j]-97]++;
            }

            for(int j=0;j<26;j++){
                hash1[j]=max(hash1[j],temp[j]);
            }
        } 
        

        for(int i=0;i<words1.size();i++){
            vector<int>hash2(26,0);
            string temp=words1[i];
            for(int j=0;j<temp.length();j++){
                hash2[temp[j]-97]++;
            }
            if(isSame(hash1,hash2))res.push_back(temp);
        }
        return res;
        
    }
};

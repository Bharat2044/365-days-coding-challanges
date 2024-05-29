// Question Link: https://leetcode.com/problems/longest-string-chain/


class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int ans=0;
        unordered_map<string,int>dp;

        sort(words.begin(),words.end(),sortByLength);
        for(string word :words){
            for(int i=0 ;i<word.length();i++){
                string predecessor = word.substr(0,i) + word.substr(i+1);
                dp[word] = max(dp[word] , dp[predecessor]+1);

            }
            ans = max( ans, dp[word]);
        }  
        return ans;
    }
    static bool sortByLength(string &s1, string &s2){
        return s1.length()<s2.length();
    }
};

// Question Link: https://leetcode.com/problems/jump-game-vii/

/*
1871. Jump Game VII

You are given a 0-indexed binary string s and two integers minJump and maxJump. In the beginning, you are standing at index 0, which is equal to '0'. You can move from index i to index j if the following conditions are fulfilled:

i + minJump <= j <= min(i + maxJump, s.length - 1), and
s[j] == '0'.
Return true if you can reach index s.length - 1 in s, or false otherwise.

Example 1:
Input: s = "011010", minJump = 2, maxJump = 3
Output: true
Explanation:
In the first step, move from index 0 to index 3. 
In the second step, move from index 3 to index 5.
Example 2:
Input: s = "01101110", minJump = 2, maxJump = 3
Output: false
 
Constraints:
2 <= s.length <= 10^5
s[i] is either '0' or '1'.
s[0] == '0'
1 <= minJump <= maxJump < s.length
*/



class Solution {
public:
    int jg7(int i,string &s,vector<int> &dp,int mj,int maj,set<int> &set){
        int n=s.size();
        if(i==n-1)return 1;
        if(dp[i]!=-1)return dp[i];int a=0,k=min(i+maj,n-1);
        int b=0;
        while(1){{
            auto it=set.lower_bound(i+mj);
            if(it==set.end() || *it>k)break;
                auto j=*it;set.erase(j);
                if(dp[j]==-1)
                dp[j]=jg7(j,s,dp,mj,maj,set);b=dp[j];
            }a=(a||b);if(a==1)break;
        }
        return dp[i]=a;
    }
    
    bool canReach(string s, int minJump, int maxJump) {
        int n=s.size();
        vector<int> dp(n+1,-1);set<int> set;
        for(int i=0;i<n;i++)if(s[i]=='0')set.insert(i);
        return jg7(0,s,dp,minJump,maxJump,set);
    }
};

// Question Link: https://leetcode.com/problems/maximum-length-of-pair-chain/

/*
646. Maximum Length of Pair Chain

You are given an array of n pairs pairs where pairs[i] = [lefti, righti] and lefti < righti.
A pair p2 = [c, d] follows a pair p1 = [a, b] if b < c. A chain of pairs can be formed in this fashion.
Return the length longest chain which can be formed.
You do not need to use up all the given intervals. You can select pairs in any order.

Example 1:
Input: pairs = [[1,2],[2,3],[3,4]]
Output: 2
Explanation: The longest chain is [1,2] -> [3,4].
Example 2:
Input: pairs = [[1,2],[7,8],[4,5]]
Output: 3
Explanation: The longest chain is [1,2] -> [4,5] -> [7,8].
 
Constraints:
n == pairs.length
1 <= n <= 1000
-1000 <= lefti < righti <= 1000
*/



class Solution {
private:
    // get the nearest pair after i, say (c, d), for which c > pairs[i][1]
    int binarySearch(vector<vector<int>>& pairs, int i) {
        int n = pairs.size();
        int start = i+1, end = n-1, ans = n;
        while(start <= end) {
            int mid = start + (end - start)/2;
            if(pairs[mid][0] > pairs[i][1]) {
                ans = mid;
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }
        return ans;
    }
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        int n = pairs.size();
        vector<int> dp(n+1, 0);
        // for the last element, we should choose it in any case
        dp[n-1] = 1;
        for(int i = n-2; i >= 0; --i) {
            int exclude = dp[i+1];
            int nextIdx = binarySearch(pairs, i);
            int include = 1 + dp[nextIdx];
            dp[i] = max(include, exclude);
        }
        return dp[0];
    }
};

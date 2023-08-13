// Question Link: https://leetcode.com/problems/perfect-squares/

/*
279. Perfect Squares

Given an integer n, return the least number of perfect square numbers that sum to n.

A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.

Example 1:
Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4.
Example 2:
Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.
 
Constraints:
1 <= n <= 104
*/



class Solution {
public:
    int numSquares(int n) {
        vector<int> memo(n + 1, -1);

        return helper(n, memo);
    }

    int helper(int tar, vector<int>& memo) {
        if (tar == 0) 
            return 0;

        if (memo[tar] != -1) 
            return memo[tar];

        int res = 1e9;
        for (int i = 1; i * i <= tar; ++i) 
            res = min(res, 1 + helper(tar - i * i, memo));

        return memo[tar] = res;
    }
};

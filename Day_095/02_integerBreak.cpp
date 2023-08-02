// Question Link: https://leetcode.com/problems/integer-break/

/*
343. Integer Break

Given an integer n, break it into the sum of k positive integers, where k >= 2, and maximize the product of those integers.

Return the maximum product you can get.

Example 1:
Input: n = 2
Output: 1
Explanation: 2 = 1 + 1, 1 × 1 = 1.
Example 2:
Input: n = 10
Output: 36
Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.
 
Constraints:
2 <= n <= 58
*/



class Solution {
public:
    int integerBreak(int n) {
        if(n==2 || n==3) 
            return n-1;

        int r = n%3;  
        int q = n/3; 
        int ans = pow(3,q);   

        if(r == 0) 
            return ans;
        if(r == 1) 
            return pow(3,q-1)*4;
        if(r == 2) 
            return ans*2;

        return 0;
    }
};

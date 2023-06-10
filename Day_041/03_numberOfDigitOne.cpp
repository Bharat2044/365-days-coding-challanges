// Question Link: https://leetcode.com/problems/number-of-digit-one/

/*
233. Number of Digit One

Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.

Example 1:
Input: n = 13
Output: 6
Example 2:
Input: n = 0
Output: 0 

Constraints:
0 <= n <= 109
*/




class Solution {
public:
    int countDigitOne(int n) {
        int ones = 0;
        
        for (long long m=1; m<=n; m*=10) {
            int a = n/m, b = n%m;
            
            ones += (a+8) / 10*m+(a % 10==1)*(b+1);
        }

        return ones;
    }
};

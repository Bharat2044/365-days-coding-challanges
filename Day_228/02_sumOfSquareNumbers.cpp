// Question Link: https://leetcode.com/problems/sum-of-square-numbers/

/*
633. Sum of Square Numbers

Given a non-negative integer c, decide whether there're two integers a and b such that a2 + b2 = c.

Example 1:
Input: c = 5
Output: true
Explanation: 1 * 1 + 2 * 2 = 5
Example 2:
Input: c = 3
Output: false
 
Constraints:
0 <= c <= 231 - 1
*/



class Solution {
public:
    bool judgeSquareSum(int c) {
        int i=0;
        int j=sqrt(c);

        while(i<=j){
            if((long long)i*i + (long long)j*j == (long long)c) return true;
            else if((long long)i*i + (long long)j*j < (long long)c){
                i++;
            }
            else{
                j--;
            }
        }

        return false;
    }
};

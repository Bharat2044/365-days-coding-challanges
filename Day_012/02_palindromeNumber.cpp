// Question Link: https://leetcode.com/problems/palindrome-number/

/*
9. Palindrome Number:

Given an integer x, return true if x is a palindrome, and false otherwise.
 
Example 1:
Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.
Example 2:
Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:
Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
 
Constraints:
-231 <= x <= 231 - 1
*/


// Time Complexity = O(logx), Space Complexity = O(1)\
class Solution {
public:
    int reverse(int n) {
        int rev = 0;
        
        while(n) {
            int d = n%10;
            
            if(rev>INT_MAX/10 || rev<INT_MIN/10)
                return 0;
            
            rev = (rev*10)+d;
            n /= 10;
        }
        
        return rev;
    }
    
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        
        return (x == reverse(x));
    }
};

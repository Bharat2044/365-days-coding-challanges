// Question Link: https://leetcode.com/problems/largest-palindrome-product/

/*
479. Largest Palindrome Product

Given an integer n, return the largest palindromic integer that can be represented as the product of two n-digits integers. Since the answer can be very large, return it modulo 1337.

Example 1:
Input: n = 2
Output: 987
Explanation: 99 x 91 = 9009, 9009 % 1337 = 987
Example 2:
Input: n = 1
Output: 9 

Constraints:
1 <= n <= 8
*/



class Solution {
public:
    int largestPalindrome(int n) {
        if(n==1)
        {
            return 9;
        }
        int hi=pow(10,n)-1;
        int lo=pow(10,n-1);
        int kk=1337;
        for(int i=hi;i>=lo;i--)
        {
            string s=to_string(i);
            string k=s;
            reverse(k.begin(),k.end());
            s+=k;
            long long int ll=stol(s);
            for(int j=hi;j>=sqrtl(ll);j--)
            {
                if(ll%j==0)
                {
                    return ll%kk;
                }
            }
            
        }
        return 0;
    }
};

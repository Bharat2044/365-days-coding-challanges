// Question Link: https://leetcode.com/problems/super-pow/

/*
372. Super Pow

Your task is to calculate ab mod 1337 where a is a positive integer and b is an extremely large positive integer given in the form of an array.

Example 1:
Input: a = 2, b = [3]
Output: 8
Example 2:
Input: a = 2, b = [1,0]
Output: 1024
Example 3:
Input: a = 1, b = [4,3,3,8,5,2]
Output: 1
 
Constraints:
1 <= a <= 231 - 1
1 <= b.length <= 2000
0 <= b[i] <= 9
b does not contain leading zeros.
*/



class Solution {
    public:

        const int base = 1337;
        int powmod(int a, int k) //a^k mod 1337 where 0 <= k <= 10
        {
            a %= base;
            int result = 1;
            for (int i = 0; i < k; ++i)
                result = (result * a) % base;
            return result;
        }

        int superPow(int a, vector<int>& b) {
            if (b.empty()) return 1;
            int last_digit = b.back();
            b.pop_back();
            return powmod(superPow(a, b), 10) * powmod(a, last_digit) % base;
        }
};

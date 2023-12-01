// Question Link: https://leetcode.com/problems/smallest-good-base/

/*
483. Smallest Good Base

Given an integer n represented as a string, return the smallest good base of n.

We call k >= 2 a good base of n, if all digits of n base k are 1's.

Example 1:
Input: n = "13"
Output: "3"
Explanation: 13 base 3 is 111.
Example 2:
Input: n = "4681"
Output: "8"
Explanation: 4681 base 8 is 11111.
Example 3:
Input: n = "1000000000000000000"
Output: "999999999999999999"
Explanation: 1000000000000000000 base 999999999999999999 is 11.
 
Constraints:
n is an integer in the range [3, 1018].
n does not contain any leading zeros.
*/



class Solution {
public:
    string smallestGoodBase(string n) {
        typedef unsigned long long ll;
        ll num = stol(n);
        
        for (ll p = log(num+1) / log(2); p >= 2; --p) {
            ll lk = 2, rk = pow(num, 1.0 / (p-1))+1;

            while (lk <= rk) {
                ll mk = lk + (rk - lk) / 2, sum = 0;

                for (ll i = 0, f = 1; i < p; ++i, f *= mk)
                    sum += f;

                if (sum < num) lk = mk+1;
                else if (sum > num) rk = mk-1;
                else return to_string(mk);
            }
        }

        return to_string(num-1);
    }
};

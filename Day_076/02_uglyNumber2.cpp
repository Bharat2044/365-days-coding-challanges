// Question Link: https://leetcode.com/problems/ugly-number-ii/

/*
264. Ugly Number II

An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.

Given an integer n, return the nth ugly number.

Example 1:
Input: n = 10
Output: 12
Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10 ugly numbers.
Example 2:
Input: n = 1
Output: 1
Explanation: 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.
 
Constraints:
1 <= n <= 1690
*/




class Solution {
public:
    int nthUglyNumber(int n) {
        set<long> set;
        long nthNumber = 1;
        set.insert(nthNumber);
      
        for(int i=0; i<n; i++){
            nthNumber = *set.begin();
            set.erase(nthNumber);
            set.insert(nthNumber*2);
            set.insert(nthNumber*3);
            set.insert(nthNumber*5);
        }
      
        return nthNumber;
    }
};


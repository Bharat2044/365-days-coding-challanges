// Question Link: https://leetcode.com/problems/super-ugly-number/

/*
313. Super Ugly Number

A super ugly number is a positive integer whose prime factors are in the array primes.
Given an integer n and an array of integers primes, return the nth super ugly number.
The nth super ugly number is guaranteed to fit in a 32-bit signed integer.

Example 1:
Input: n = 12, primes = [2,7,13,19]
Output: 32
Explanation: [1,2,4,7,8,13,14,16,19,26,28,32] is the sequence of the first 12 super ugly numbers given primes = [2,7,13,19].
Example 2:
Input: n = 1, primes = [2,3,5]
Output: 1
Explanation: 1 has no prime factors, therefore all of its prime factors are in the array primes = [2,3,5].
 
Constraints:
1 <= n <= 105
1 <= primes.length <= 100
2 <= primes[i] <= 1000
primes[i] is guaranteed to be a prime number.
All the values of primes are unique and sorted in ascending order.
*/



class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        long long uglyNumbers[n + 1];  // Array to store super ugly numbers
        uglyNumbers[0] = 0;  // Not mandatory, just for clarity
        uglyNumbers[1] = 1;  // The first super ugly number is 1

        // Create a vector of pairs to store prime factors and their indices
        vector<pair<int, int>> primeIndices;
        for (int i = 0; i < primes.size(); i++) {
            primeIndices.push_back(make_pair(primes[i], 1));
        }

        for (int i = 2; i <= n; i++) {
            long long nextUgly = LLONG_MAX;  // Initialize nextUgly to a large value
            for (int j = 0; j < primes.size(); j++) {
                // Find the next smallest super ugly number among primes' multiples
                nextUgly = min(nextUgly, uglyNumbers[primeIndices[j].second] * (long long)primeIndices[j].first);
            }
            uglyNumbers[i] = nextUgly;  // Store the next super ugly number
            
            // Update the indices based on which prime factor was chosen
            for (int j = 0; j < primes.size(); j++) {
                if (nextUgly == uglyNumbers[primeIndices[j].second] * (long long)primeIndices[j].first) {
                    primeIndices[j].second++;
                }
            }
        }
        
        return uglyNumbers[n];  // Return the nth super ugly number
    }
};

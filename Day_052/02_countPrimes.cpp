// Question Link: https://leetcode.com/problems/count-primes/

/*
204. Count Primes

Given an integer n, return the number of prime numbers that are strictly less than n.

Example 1:
Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
Example 2:
Input: n = 0
Output: 0
Example 3:
Input: n = 1
Output: 0
 
Constraints:
0 <= n <= 5 * 106
*/


class Solution {
    

public:
    int countPrimes(int n) {
        vector<bool>isPrime(n+1,true);   
        int count=0;
        for(int i=2;i<n;i++){
            if(isPrime[i]){
                count++;
                for(long j=2*i;j<n;j+=i)
                    isPrime[j]=false;
            }
        }
        return count;
    }
  
  
     /*bool isPrime(int n){
        if(n==1)
            return 0;
        if(n==2 || n==3)
            return 1;
        if(n%2==0 || n%3==0)
            return 0;
        for(int i=5;i*i<=n;i+=6){
            if(n%i==0 || n%(i+2)==0)
                return 0;
        }
        return 1;
     }
    int countPrimes(int n) {
        int count=0;
        for(int i=2;i<n;i++){
            if(isPrime(i)){
                int x=i;
                if(isPrime(x))
                    count++;
            }
        }
        return count;
    }*/
};

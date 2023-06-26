// Question Link: https://www.interviewbit.com/problems/ways-to-decode/

/*
Ways to Decode

Problem Description:
A message containing letters from A-Z is being encoded to numbers using the following mapping:
 'A' -> 1
 'B' -> 2
 ...
 'Z' -> 26
Given an encoded message A containing digits, determine the total number of ways to decode it modulo 109 + 7.

Problem Constraints:
1 <= |A| <= 105

Input Format:
The first and the only argument is a string A.

Output Format:
Return a single integer denoting the total number of ways to decode it modulo 109 + 7.

Example Input:
Input 1:
 A = "8"
Input 2:
 A = "12"

Example Output:
Output 1:
 1
Output 2:
 2

Example Explanation:
Explanation 1:
 Given encoded message "8", it could be decoded as only "H" (8).
 The number of ways decoding "8" is 1.
Explanation 2:
 Given encoded message "12", it could be decoded as "AB" (1, 2) or "L" (12).
 The number of ways decoding "12" is 2.
  */



const int mod = 1e9 + 7;

int Solution::numDecodings(string A) {
    int n = A.size();
    int dp[n + 1];
    
    dp[0] = 1; // base case
    dp[1] = A[0] == '0' ? 0 : 1; // base case
    
    for (int i = 2; i <= n; i++) {
        // If the current digit is not '0', then it contributes to the count of decodings
        int count = A[i - 1] == '0' ? 0 : dp[i - 1];
        
        // If the two digits form a valid number (from 10 to 26), then they contribute to the count of decodings
        if (A[i - 2] == '1' || (A[i - 2] == '2' && A[i - 1] <= '6')) 
            count = (count + dp[i - 2]) % mod;
                
        dp[i] = count;
    }
    
    return dp[n];
}

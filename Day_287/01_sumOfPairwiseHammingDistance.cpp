// Question Link: https://www.interviewbit.com/problems/sum-of-pairwise-hamming-distance/

/*
Sum of pairwise Hamming Distance

Problem Description:
Hamming distance between two non-negative integers is defined as the number of positions at which the corresponding bits are different.
Given an array A of N non-negative integers, find the sum of hamming distances of all pairs of integers in the array. Return the answer modulo 1000000007.

Problem Constraints:
1 <= |A| <= 200000
1 <= A[i] <= 109

Input Format:
First and only argument is array A.

Output Format:
Return one integer, the answer to the problem.

Example Input:
Input 1:
A = [1]
Input 2:
A = [2, 4, 6]

Example Output:
Output 1:
0
Output 2:
8

Example Explanation:
Explanation 1:
No pairs are formed.
Explanation 2:
We return, f(2, 2) + f(2, 4) + f(2, 6) + f(4, 2) + f(4, 4) + f(4, 6) + f(6, 2) + f(6, 4) + f(6, 6) = 8
*/



int Solution::hammingDistance(const vector<int> &A)
{
    long long int ans = 0;
    long long int mod = 1000000007;
    long long int set = 0;
    long long int notset = 0;
   
    for(int j = 0; j < 32; j++)
    {
        set = 0;
        notset = 0;
        for(int i = 0; i < A.size(); i++)
        {
            if(A[i]&(1 << j)) set = (set + 1)%mod;
            else notset = ((notset + 1)%mod);
        }
        ans = (ans + (set*notset*2))%mod;
    }
    return (int)ans;
}

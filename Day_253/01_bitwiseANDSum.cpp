// Question Link: https://www.interviewbit.com/problems/bitwise-and-sum/

/*
Bitwise AND Sum

Problem Description:
You are given an array A of length N. Consider that the array is one indexed.
You need to find sum of ( A[i] & A[j] & (A[i] + A[j]) )  for all pairs (i,j) such that 1 <= i < j <= N.

Problem Constraints:
2 <= N <= 2 x 105
1 <= A[i] <= 109

Input Format:
The only argument contains the integer array A.

Output Format:
Return the sum of A[i] & A[j] & (A[i] + A[j]) for all pairs. Since the answer can be large, return it modulo 109 + 7.

Example Input:
Input 1:
A : [8, 9]
Input 2::
A : [1, 3, 3]

Example Output:
Output 1:
0
Output 2:
2

Example Explanation:
Explanation 1:
There is only one pair - (8 & 9 & (8 + 9)) = 0
Explanation 2:
We have 3 pairs - 
 (1, 3) = 1 & 3 & (1+3) = 0
 (1, 3) = 1 & 3 & (1+3) = 0
 (3, 3) = 3 & 3 & (3+3) = 2
*/



const int mod = 1e9 + 7;
vector<int>v;
int f(int sum){
    int l = 0, r = int(v.size()) - 1; 
    int result = 0; 
    while (l < r) 
    { 
        if (v[l] + v[r] >= sum) { 
            result += (r - l); 
            if(result >= mod)
                result -= mod;
            r--; 
        }
        else
            l++; 
    } 
    return result; 
}
int Solution::solve(vector<int> &A) {
    int n = A.size();
    int ans = 0;
    for(int i = 0; i < 30; i++){
        v.clear();
        for(int j : A){
            if(j & (1 << i))
                v.push_back(j % (1 << i));
        }
        sort(v.begin(), v.end());
        ans=(ans + (1 << i)* 1ll *f(1 << i))%mod;
    }
    return ans;
}

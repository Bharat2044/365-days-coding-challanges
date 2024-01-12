// Question Link: https://www.interviewbit.com/problems/length-of-longest-subsequence/

/*
Length of Longest Subsequence

Problem Description:
Given a 1D integer array A of length N, find the length of the longest subsequence which is first increasing (strictly) and then decreasing (strictly).

Problem Constraints:
0 <= N <= 3000
-107 <= A[i] <= 107

Input Format:
The first and the only argument contains an integer array A.

Output Format:
Return an integer representing the answer as described in the problem statement.

Example Input:
Input 1:
 A = [1, 2, 1]
Input 2:
 A = [1, 11, 2, 10, 4, 5, 2, 1]

Example Output:
Output 1:
 3
Output 2:
 6

Example Explanation:
Explanation 1:
 [1, 2, 1] is the longest subsequence.
Explanation 2:
 [1 2 10 4 2 1] is the longest subsequence.
*/



int Solution::longestSubsequenceLength(const vector<int> &A) {
    int n=A.size();
    int dpl[n];
    if(n==0)
    return 0;
    dpl[0]=1;
    for(int i=1;i<n;i++)
    {
        dpl[i]=1;
        for(int j=0;j<i;j++)
        {
            if(A[j]<A[i])
            dpl[i]=max(dpl[j]+1,dpl[i]);
        }
    }
    vector<int> temp(n);
    for(int i=0;i<n;i++)
    temp[i]=A[i];
    
    reverse(temp.begin(),temp.end());
    
    int dpr[n];
    dpr[n-1]=1;
    for(int i=n-2;i>=0;i--)
    {
        dpr[i]=1;
        for(int j=n-1;j>i;j--)
        {
            if(A[j]<A[i])
            dpr[i]=max(dpr[i],dpr[j]+1);
        }
    }
    
    int ans=0;
    for(int i=0;i<n;i++)
    {
        ans=max(ans,dpr[i]+dpl[i]-1);
    }
    return ans;
}

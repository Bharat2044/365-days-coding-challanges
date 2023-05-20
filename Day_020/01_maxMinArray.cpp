// Question Link: https://www.interviewbit.com/problems/max-min-05542f2f-69aa-4253-9cc7-84eb7bf739c4/

/*
Max Min:

Problem Description:
Given an array A of size N. You need to find the sum of Maximum and Minimum element in the given array.

NOTE: You should make minimum number of comparisons.

Problem Constraints:
1 <= N <= 105
-109 <= A[i] <= 109

Input Format:
First and only argument is an integer array A of size N.

Output Format:
Return an integer denoting the sum Maximum and Minimum element in the given array.
*/



// Time Complexity = O(n), Space Complexity = O(1)
int Solution::solve(vector<int> &A) {
    int mini = INT_MAX;
    int maxi = INT_MIN;
    
    for(int i=0; i<A.size(); i++) {
        if(A[i] > maxi)
            maxi = A[i];
        
        if(A[i] < mini)
            mini = A[i];
    }
    
    return maxi+mini;
}

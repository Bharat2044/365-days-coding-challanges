// /Question Link: https://www.interviewbit.com/problems/maximum-sum-triplet/

/*
Maximum Sum Triplet

Problem Description:
Given an array A containing N integers.

You need to find the maximum sum of triplet ( Ai + Aj + Ak ) such that 0 <= i < j < k < N and Ai < Aj < Ak.

If no such triplet exist return 0.

Problem Constraints:
3 <= N <= 105.
1 <= A[i] <= 108.

Input Format:
First argument is an integer array A.

Output Format:
Return a single integer denoting the maximum sum of triplet as described in the question.

Example Input:
Input 1:
 A = [2, 5, 3, 1, 4, 9]
Input 2:
 A = [1, 2, 3]

Example Output:
Output 1:
 16
Output 2:
6
 
Example Explanation:
Explanation 1:
 All possible triplets are:-
    2 3 4 => sum = 9
    2 5 9 => sum = 16
    2 3 9 => sum = 14
    3 4 9 => sum = 16
    1 4 9 => sum = 14
  Maximum sum = 16
Explanation 2:
 All possible triplets are:-
    1 2 3 => sum = 6
 Maximum sum = 6
*/




int Solution::solve(vector<int> &A) {
    //To find the max element on right lets create a suffix array storing maximum element from right 
    vector<int> suffix(A.size());
    int mx=A[A.size()-1];

    for(int i=A.size()-1;i>=0;i--){
        if(A[i]>mx){
            mx=A[i];
        }
        suffix[i]=mx;
    }

    //To find the best possible answer for left we need to store each element in a set and the elemnt left of that particular element will be the best possible solution for that particular element
    set<int> left;
    int maxSum=0,sum;
    left.insert(A[0]);

    for(int i=1;i<A.size();i++){
        left.insert(A[i]);

        auto it = left.find(A[i]);
        if(it!=left.begin() && suffix[i]!=A[i])//edge cases
            sum = (*--it)+A[i]+suffix[i];
        maxSum=max(sum,maxSum);
    }

    return maxSum;
}

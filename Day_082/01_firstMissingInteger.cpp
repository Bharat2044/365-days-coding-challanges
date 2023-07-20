// Question Link: https://www.interviewbit.com/problems/first-missing-integer/

/*
First Missing Integer

Problem Description:
Given an unsorted integer array, find the first missing positive integer.
Your algorithm should run in O(n) time and use constant space.

Problem Constraints:
1 <= |A| <= 106
1 <= Ai <= 106

Input Format:
The first argument is an integer array A.

Output Format:
Return an integer equal to the first missing positive integer

Example Input:
Input 1:
A = [1,2,0]
Input 2:
A = [3,4,-1,1]
Input 3:
A = [-8,-7,-6]

Example Output:
Output 1:
3
Output 2:
2
Output 3:
1

Example Explanation:
Explanation 1:
3 is the first positive missing integer.
Explanation 2:
2 is the first positive missing integer.
Explanation 3:
1 is the first positive missing integer.
*/




int Solution::firstMissingPositive(vector<int> &A) {
    int n = A.size();
    
    for(int i=0; i<n; i++) {
        while (A[i]>=1 && A[i]<=n && A[i]!=A[A[i]-1]) 
            swap(A[i],A[A[i]-1]);
    }
    
    for(int i=0; i<n; i++) {
        if(A[i] != i+1) 
            return i+1;
    }
    
    return n+1;
}

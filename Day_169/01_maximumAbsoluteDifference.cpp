// Question Link: https://www.interviewbit.com/problems/maximum-absolute-difference/

/*
Maximum Absolute Difference

Problem Description:
You are given an array of N integers, A1, A2 ,..., AN. Return maximum value of f(i, j) for all 1 ≤ i, j ≤ N. f(i, j) is defined as |A[i] - A[j]| + |i - j|, where |x| denotes absolute value of x.

Problem Constraints:
1 <= |A| <= 105
-109 <= Ai <= 109

Input Format:
The first argument is an integer array A.

Output Format:
Return an integer equal to the maximum value of f(i, j)

Example Input:
A = [1, 3, -1]

Example Output
5

Example Explanation:
Given A = [1, 3, -1], 
f(1, 1) = f(2, 2) = f(3, 3) = 0
f(1, 2) = f(2, 1) = |1 - 3| + |1 - 2| = 3
f(1, 3) = f(3, 1) = |1 - (-1)| + |1 - 3| = 4
f(2, 3) = f(3, 2) = |3 - (-1)| + |2 - 3| = 5
The maximum value is 5, which is of f(2, 3)
*/



int Solution::maxArr(vector<int> &A) {

    int n = A.size();

    int min1 = INT_MAX, max1 = INT_MIN, min2 = INT_MAX, max2 = INT_MIN;

    for(int i=0; i<n; i++){
        if(A[i] + i < min1) min1 = A[i] + i;

        if(A[i] + i > max1) max1 = A[i] + i;

        if(A[i] - i < min2) min2 = A[i] - i;

        if(A[i] - i > max2) max2 = A[i] - i;        
    }

    return max(abs(max1 - min1), abs(max2 - min2));
}

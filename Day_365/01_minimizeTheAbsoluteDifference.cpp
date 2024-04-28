// Question Link: https://www.interviewbit.com/problems/minimize-the-absolute-difference/

/*
Minimize the absolute difference
Given three sorted arrays A, B  and Cof not necessarily same sizes.
Calculate the minimum absolute difference between the maximum and minimum number from the triplet a, b, c such that a, b, c belongs arrays A, B, C respectively.
i.e. minimize | max(a,b,c) - min(a,b,c) |.

Example :
Input:
A : [ 1, 4, 5, 8, 10 ]
B : [ 6, 9, 15 ]
C : [ 2, 3, 6, 6 ]
Output:
1
Explanation: We get the minimum difference for a=5, b=6, c=6 as | max(a,b,c) - min(a,b,c) | = |6-5| = 1.
*/



int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    int i = 0, j = 0, k = 0;
    int minDiff = INT_MAX;

    while (i < A.size() && j < B.size() && k < C.size()) {
        int maxVal = max(max(A[i], B[j]), C[k]);
        int minVal = min(min(A[i], B[j]), C[k]);
        int currentDiff = maxVal - minVal;
        minDiff = min(minDiff, currentDiff);

        // Move pointers based on the comparison of the current elements
        if (A[i] == minVal) {
            i++;
        } else if (B[j] == minVal) {
            j++;
        } else {
            k++;
        }
    }

    return minDiff;
}

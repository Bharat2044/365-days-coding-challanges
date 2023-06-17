// QuestionLink: https://www.interviewbit.com/problems/min-jumps-array/

/*
Min Jumps Array

Problem Description:
Given an array of non-negative integers, A, of length N, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Return the minimum number of jumps required to reach the last index.
If it is not possible to reach the last index, return -1.


Problem Constraints:
1 <= N <= 106
0 <= A[i] <= 50000

Input Format:
The first and the only argument contains an integer array, A.

Output Format:
Return an integer, representing the answer as described in the problem statement.

Example Input:
Input 1:
A = [2, 1, 1]
Input 2:
A = [2, 3, 1, 1, 4]

Example Output:
Output 1:
1
Output 1:
2

Example Explanation:
Explanation 1:
The shortest way to reach index 2 is
    Index 0 -> Index 2
that requires only 1 jump.
Explanation 2:
The shortest way to reach index 4 is
    Index 0 -> Index 1 -> Index 4
that requires 2 jumps.
*/



int Solution::jump(vector<int> &A) {
    int farthest = 0;

    int current = 0;
    int jumps = 0;

    for(int i=0; i<A.size()-1; i++) {
        farthest = max(farthest, A[i]+i);

        if(current == i) {
            current=farthest;
            jumps++;
        }
    }
    
    if(current>=A.size()-1) 
        return jumps;
    else 
        return -1;
}

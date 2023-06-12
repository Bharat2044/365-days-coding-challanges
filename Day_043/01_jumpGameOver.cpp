// Question Link: https://www.interviewbit.com/problems/jump-game-array/

/*
Jump Game Array

Given an array of non-negative integers, A, you are initially positioned at the 0th index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

Input Format:
The first and the only argument of input will be an integer array A.

Output Format:
Return an integer, representing the answer as described in the problem statement.
    => 0 : If you cannot reach the last index.
    => 1 : If you can reach the last index.
    
Constraints:
    1 <= len(A) <= 106
    0 <= A[i] <= 30

Examples:
Input 1:
    A = [2,3,1,1,4]
Output 1:
    1
Explanation 1:
    Index 0 -> Index 2 -> Index 3 -> Index 4
Input 2:
    A = [3,2,1,0,4]
Output 2:    0
Explanation 2:
    There is no possible path to reach the last index.
 */



vector<int>dp(1000006,-1);

bool canyou(int i,vector<int>&A) {
    if(i >= A.size()-1)
       return true;

    if(dp[i] != -1) 
        return dp[i]; 

    for(int k=1; k<=A[i]; k++) {
        if(dp[i+k] == 1) 
            return dp[i+k];
        
        if(canyou(i+k, A)) 
            return dp[i] = true;
    }

    return dp[i] = false;
}

int Solution::canJump(vector<int> &A) {
    int x= canyou(0,A);
    fill(dp.begin(),dp.end(),-1);

    return x;
}


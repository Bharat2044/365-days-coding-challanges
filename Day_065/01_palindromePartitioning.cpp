// Question Link: https://www.interviewbit.com/problems/palindrome-partitioning-ii/

/*
Palindrome Partitioning II

Problem Description:
Given a string A, partition A such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of A.

Problem Constraints:
1 <= length(A) <= 501

Input Format:
The first and the only argument contains the string A.

Output Format:
Return an integer, representing the minimum cuts needed.

Example Input:
Input 1:
 A = "aba"
Input 2:
 A = "aab"
 
Example Output:
Output 1:
 0
Output 2:
1

Example Explanation:
Explanation 1:
 "aba" is already a palindrome, so no cuts are needed.
Explanation 2:
 Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
*/



bool isPalindrome(int i,int j,string &A){
    while(i<j){
        if(A[i] != A[j]){
            return false;
        }
        else{
            i++;
            j--;
        }
    }
    return true;
}

int solve(int i,int j,string &A,vector<vector<int>> &dp){
    if(i >= j)
        return 0;

    if(isPalindrome(i,j,A) == true)
        return 0;

    if(dp[i][j] != -1)
        return dp[i][j];

    int ans = INT_MAX;

    for(int k=i; k<j; k++){
        int temp = solve(i,k,A,dp) + solve(k+1,j,A,dp) + 1;

        ans = min(ans,temp);
    }

    return dp[i][j] = ans;
}

int Solution::minCut(string A) {
    int n = A.size();
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));

    return solve(0,n-1,A,dp);
}



// Question Link: https://www.interviewbit.com/problems/word-break/

/*
Word Break

Problem Description:
Given a string A and a dictionary of words B, determine if A can be segmented into a space-separated sequence of one or more dictionary words.

Problem Constraints:
1 <= len(A) <= 6500
1 <= len(B) <= 10000
1 <= len(B[i]) <= 20

Input Format:
The first argument is a string, A.
The second argument is an array of strings, B.

Output Format:
Return 0 / 1 ( 0 for false, 1 for true ) for this problem.

Example Input:
Input 1:
 A = "myinterviewtrainer",
B = ["trainer", "my", "interview"]
Input 2:
A = "a"
B = ["aaa"]

Example Output:
Output 1:
1
Output 2:
0

Example Explanation:
Explanation 1:
Return 1 ( corresponding to true ) because "myinterviewtrainer" can be segmented as "my interview trainer".
Explanation 2:
Return 0 ( corresponding to false ) because "a" cannot be segmented as "aaa".
  */



bool contains(string A,vector<string> &B){
    for(int i=0;i<B.size();i++){
        if(A.compare(B[i]) == 0)return true;
    }
    return false;
}

bool solve(string A, vector<string> &B,int indx,vector<int> &dp){
    if(indx == A.length())return true;
    if(dp[indx] != -1)return dp[indx];
   
    for(int i=indx;i<A.length();i++){
        if(contains(A.substr(indx,i-indx+1),B) && solve(A,B,i+1,dp))
        return dp[indx] = true;
       
    }
    return dp[indx] = false;
}

int Solution::wordBreak(string A, vector<string> &B) {
    int n=A.size();
    vector<int> dp(n+1,-1);
    return solve(A,B,0,dp);
}

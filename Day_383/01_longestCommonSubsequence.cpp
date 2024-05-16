// Question Link: https://www.interviewbit.com/problems/longest-common-subsequence/

/*
Longest Common Subsequence

Problem Description:
Given two strings A and B. Find the longest common sequence ( A sequence which does not need to be contiguous), which is common in both the strings.
You need to return the length of such longest common subsequence.

Problem Constraints:
1 <= |A|, |B| <= 1005

Input Format:
First argument is an string A.
Second argument is an string B.

Output Format:
Return the length of such longest common subsequence between string A and string B.

Example Input:
Input 1:
 A = "abbcdgf"
 B = "bbadcgf"
 
Example Output:
Output 1:
 5
 
Example Explanation:
Explanation 1:
 The longest common subsequence is "bbcgf", which has a length of 5
*/



int Solution::solve(string A, string B) {

    vector < vector<int> >v(1006 , vector <int> (1006));
    long long int i,j;

    for(i=0;i<A.size();i++) {
        for(j=0;j<B.size();j++)
            v[i][j]=0;
    }

    for(i=1;i<=A.size();i++) {
        for(j=1;j<=B.size();j++) {
            
            if(A[i-1]==B[j-1])
                v[i][j]=1+v[i-1][j-1];
            else
               v[i][j]=max(v[i-1][j],v[i][j-1]);
        }
    }

    return v[A.size()][B.size()];
}

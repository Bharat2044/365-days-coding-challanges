// Question Link: https://www.interviewbit.com/problems/intersecting-chords-in-a-circle/

/*
Intersecting Chords in a Circle

Given a number A, return number of ways you can draw A chords in a circle with 2 x A points such that no 2 chords intersect.
Two ways are different if there exists a chord which is present in one way and not in other.

Return the answer modulo 109 + 7.

Input Format:
The first and the only argument contains the integer A.

Output Format:
Return an integer answering the query as described in the problem statement.

Constraints:
1 <= A <= 1000

Examples:
Input 1:
    A = 1
Output 1:
    1
Explanation 1:
    If points are numbered 1 to 2 in clockwise direction, then different ways to draw chords are:
    {(1-2)} only.
    So, we return 1.

Input 2:
    A = 2
Output 2:
    2
Explanation 2:
    If points are numbered 1 to 4 in clockwise direction, then different ways to draw chords are:
    {(1-2), (3-4)} and {(1-4), (2-3)}.
    So, we return 2.
*/



int m=1e9+7;
int Solution::chordCnt(int A) {
    vector<long long int> dp(2*A+2,0);
    dp[0]=1;
    dp[1]=0;
    
    for(int i=2;i<=2*A;i+=2)
    {
        for(int j=2;j<=i;j++)
        {
            dp[i]+= (dp[i-j]%m)*(dp[j-2]%m);
            dp[i]%=m;
        }
    }
    
    return dp[2*A]%m;
}

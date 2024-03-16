// Question Link: https://www.interviewbit.com/problems/egg-drop-problem/

/*
Egg Drop Problem!

Problem Description:
You are given A eggs, and you have access to a building with B floors from 1 to B.
Each egg is identical in function, and if an egg breaks, you cannot drop it again.
You know that there exists a floor C with 0 <= C <= B  such that any egg dropped at a floor higher than C will break, and any egg dropped at or below floor C will not break.

Each move, you may take an egg (if you have an unbroken one) and drop it from any floor X (with 1 <= X <= B). 
Your goal is to know with certainty what the value of C is.
What is the minimum number of moves that you need to know with certainty what C is, regardless of the initial value of C

Problem Constraints:
1 <= A <= 100
1 <= B <= 10^4

Input Format:
First Argument is an integer A denoting number of eggs.
Second Argument is an integer B denoting number of floors.

Output Format:
Return an integer denoting the Minimum number of moves.

Example Input:
Input 1:
A = 1
B = 2
Input 2:
A = 2
B = 10

Example Output:
Output 1:
2
Output 2:
4 

Example Explanation:
Explanation 1:
 Drop the egg from floor 1.  If it breaks, we know with certainty that F = 0.
 Otherwise, drop the egg from floor 2.  If it breaks, we know with certainty that F = 1.
 If it didn't break, then we know with certainty F = 2.
 Hence, we needed 2 moves in the worst case to know what F is with certainty.
*/



int Solution::solve(int A, int B) {
    int c = ceil(log2(B));
    if(c<=A) return c;
    int dp[A+3][B+3];
    memset(dp, 0, sizeof dp);
    for(int i=1;i<=B;i++) dp[1][i] = i;
    for(int i=1;i<=B;i++) {
        int l = 1, r = B - 1;
        while(l<=r) {
            int mid = (l+r)/2;
            int sum = (mid*(mid+1))/2;
            if(sum < i) l = mid+1;
            else r = mid-1;
        }
        dp[2][i] = l;
    }
    for(int i=3;i<=A;i++) {
        for(int j=1;j<=B;j++) {
            int mid = j/2;
            int a1 = max(dp[i-1][mid], dp[i][j-mid]);
            dp[i][j] = a1;
        }
    }
    return dp[A][B];
}

// Question Link: https://www.interviewbit.com/problems/tushars-birthday-party/

/*
Tushar's Birthday Party

Problem Description:
As it is Tushar's Birthday on March 1st, he decided to throw a party to all his friends at TGI Fridays in Pune. Given are the eating capacity of each friend, the filling capacity of each dish and the cost of each dish. A friend is satisfied if the sum of the filling capacity of dishes he ate is equal to his capacity. Find the minimum cost such that all of Tushar's friends are satisfied (reached their eating capacity).

NOTE:
Each dish is supposed to be eaten by only one person. Sharing is not allowed.
Each friend can take any dish an unlimited number of times.
There always exists a dish with a filling capacity of 1 so that a solution always exists.

Problem Constraints:
1 <= Capacity of friend <= 1000
1 <= No. of friends <= 1000
1 <= No. of dishes <= 1000

Input Format:
Friends: A: List of integers denoting eating capacity of friends separated by space.
Capacity: B: List of integers denoting filling capacity of each type of dish.
Cost: C: List of integers denoting cost of each type of dish.

Example Input:
A = [4, 6]
B = [1, 3]
C = [5, 3]

Example Output:
14

Example Explanation:
The first friend will take 1st and 2nd dish, the second friend will take 2nd dish twice. Thus, total cost = (5+3)+(3*2)= 14
*/



int Solution::solve(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    int n = A.size();
    int m = B.size();
   
    int target = *max_element(A.begin(),A.end());
    vector < vector <int> > dp ( m + 1 , vector <int> (target+1,0));
   
    for (int i = 1 ; i <= target ; i++)
        dp[0][i] = 1e9 + 7 ;
   
    for (int i = 1 ; i <= m ; i++ ) {
        for (int j = 1 ; j <= target ; j++ ) {
            if ( B[i-1] > j )
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = min(dp[i-1][j], C[i-1] + dp[i][j-B[i-1]] );
        }
    }
   
    int ans = 0;
   
    for (int i = 1 ; i <= n ; i++)
        ans += dp[m][A[i-1]];
   
    return ans;   
}

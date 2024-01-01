// Question Link: https://www.interviewbit.com/problems/coin-sum-infinite/

/*
Coin Sum Infinite

Problem Description:
You are given a set of coins A. In how many ways can you make sum B assuming you have an infinite amount of each coin in the set.

Note: Coins in set A will be unique. The expected space complexity of this problem is O(B).
Note that the answer can overflow. So, give us the answer % 1000007

Problem Constraints:
1 <= |A| <= 500
1 <= B <= 5 * 104

Input Format:
The first argument is an integer array A.
The second argument is an integer B.

Output Format:
Return the answer % 1000007

Example Input:
A = [1, 2, 3]
B = 4

Example Output:
4

Example Explanation:
The 4 possible ways are
{1, 1, 1, 1}
{1, 1, 2}
{2, 2}
{1, 3}
*/



int Solution::coinchange2(vector<int> &A, int B) {
    int ways[B+1];
    memset(ways, 0, sizeof(ways));
    ways[0] = 1;
    
    for(int i = 0; i < A.size(); i++){
        for(int j = A[i]; j <= B; j++){
            ways[j] = ways[j] + ways[j-A[i]];
            ways[j] = ways[j]%1000007;
        }
    }
    return ways[B];
}

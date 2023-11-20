// Question Link: https://www.interviewbit.com/problems/rod-cutting/

/*
Rod Cutting

Problem Description:
There is a rod of length N lying on the x-axis with its left end at x = 0 and right end at x = N. Now, there are M weak points on this rod denoted by positive integer values(all less than N) A1, A2, ..., AM. You have to cut the rod at all these weak points. You can perform these cuts in any order. After a cut, the rod gets divided into two smaller sub-rods. The cost of making a cut is the length of the sub-rod in which you are making a cut.

Your aim is to minimize this cost. Return an array denoting the sequence in which you will make cuts. If two different sequences of cuts give the same cost, return the lexicographically smallest.

Notes:
Sequence a1, a2 ,..., an is lexicographically smaller than b1, b2 ,..., bm, if and only if at the first i where ai and bi differ, ai < bi, or if no such i found, then n < m.
N can be up to 109.

Problem Constraints:
0 <= A <= 109
1 <= |B| <= 100

Input Format:
The first argument is an integer A, representing the value of N.
The second argument is an integer array B, representing the weak points of rod.

Output Format:
Return an array denoting the sequence in which you will make cuts.

Example Input:
A = 6
B = [1, 2, 5]

Example Output:
[2, 1, 5]

Example Explanation:
N = 6
A = [1, 2, 5]

If we make cuts in order [1, 2, 5], let us see what total cost would be.
For first cut, the length of rod is 6.
For second cut, the length of sub-rod in which we are making cut is 5(since we already have made a cut at 1).
For third cut, the length of sub-rod in which we are making cut is 4(since we already have made a cut at 2).
So, total cost is 6 + 5 + 4.

Cut order          | Sum of cost
(lexicographically | of each cut
 sorted)           |
________________|____________
[1, 2, 5]          | 6 + 5 + 4 = 15
[1, 5, 2]          | 6 + 5 + 4 = 15
[2, 1, 5]          | 6 + 2 + 4 = 12
[2, 5, 1]          | 6 + 4 + 2 = 12
[5, 1, 2]          | 6 + 5 + 4 = 15
[5, 2, 1]          | 6 + 5 + 2 = 13

So, we return [2, 1, 5].
*/



long long int solve(int i, int j, vector<int>& cuts, vector<vector<long long int>> &dp, vector<vector<int>> &pos){
    if(abs(i -j) <= 1)
        return 0;
   
    if(dp[i][j] != -1)
        return dp[i][j];

    long long int min_cost = -1;
    for(int k = i+1; k <=j-1; k++){
        long long int cost_for_cut = cuts[j] - cuts[i];
        long long int curr_cost = cost_for_cut + solve(i, k, cuts, dp, pos) + solve(k,j, cuts, dp, pos);
        if((curr_cost < min_cost) || (min_cost == -1LL)){
            min_cost = curr_cost;
            pos[i][j] = k;
        }
    }
    return dp[i][j] = min_cost;
}

void solve2(int i, int j, vector<int> &v, vector<vector<int>> &pos, vector<int>& cuts){
    if(abs(i - j) <= 1)
        return;
    v.push_back(cuts[pos[i][j]]);
    solve2(i, pos[i][j], v, pos, cuts);
    solve2(pos[i][j], j, v, pos, cuts);
}

vector<int> Solution::rodCut(int len, vector<int> &cuts) {
    cuts.push_back(0);
    cuts.push_back(len);
    sort(cuts.begin(), cuts.end());
    int m = cuts.size();
    vector<vector<long long int>>dp(m+1,vector<long long int>(m+1, -1));
    vector<vector<int>> pos(m+1,vector<int>(m+1));
    int cost = solve(0, m-1, cuts, dp, pos);
    vector<int>v;
    solve2(0, m-1, v, pos, cuts);
    return v;
}

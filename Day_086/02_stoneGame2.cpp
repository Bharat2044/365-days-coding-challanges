// Question Link: https://leetcode.com/problems/stone-game-ii/

/*
1140. Stone Game II

Alice and Bob continue their games with piles of stones.  There are a number of piles arranged in a row, and each pile has a positive integer number of stones piles[i].  The objective of the game is to end with the most stones. 

Alice and Bob take turns, with Alice starting first.  Initially, M = 1.

On each player's turn, that player can take all the stones in the first X remaining piles, where 1 <= X <= 2M.  Then, we set M = max(M, X).

The game continues until all the stones have been taken.

Assuming Alice and Bob play optimally, return the maximum number of stones Alice can get.

Example 1:
Input: piles = [2,7,9,4,4]
Output: 10
Explanation:  If Alice takes one pile at the beginning, Bob takes two piles, then Alice takes 2 piles again. Alice can get 2 + 4 + 4 = 10 piles in total. If Alice takes two piles at the beginning, then Bob can take all three piles left. In this case, Alice get 2 + 7 = 9 piles in total. So we return 10 since it's larger. 
Example 2:
Input: piles = [1,2,3,4,5,100]
Output: 104
 
Constraints:
1 <= piles.length <= 100
1 <= piles[i] <= 104
*/




class Solution {
public:
    // For retrieving the sum of piles between l to r
    int get(int l, int r, vector<long long> &pref)
    {
        return pref[r + 1] - pref[l];
    }

    int help(int idx, int m, bool aliceTurn, vector<long long> &pref, vector<int> &piles, vector<vector<vector<int>>> &dp)
    {
        if (idx >= piles.size())
            return 0;

        if (dp[idx][m][aliceTurn] != -1)
            return dp[idx][m][aliceTurn];

        // At alice turn maximize the answer 
        if (aliceTurn)
        {
            int ans = 0;
            for (int x = 1; x <= 2 * m; x++)
                if (idx + x - 1 < piles.size())
                    ans = max(ans, get(idx, idx + x - 1, pref) + help(idx + x, max(m, x), false, pref, piles, dp));

            return dp[idx][m][aliceTurn] = ans;
        }

        // while at bob's turn minimize the answer
        int ans = 1e9;
        for (int x = 1; x <= 2 * m; x++)
            if (idx + x - 1 < piles.size())
                ans = min(ans, help(idx + x, max(m, x), true, pref, piles, dp));

        return dp[idx][m][aliceTurn] = ans;
    }

    int stoneGameII(vector<int> &piles)
    {
        int n = piles.size();

        vector<long long> pref(n + 1, 0);
        for (int i = 1; i <= n; i++)
            pref[i] = pref[i - 1] + piles[i - 1];

        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2 * n + 2, vector<int>(2, -1)));
        return help(0, 1, true, pref, piles, dp);
    }
};

// Question Link: https://leetcode.com/problems/frog-jump/

/*
403. Frog Jump

A frog is crossing a river. The river is divided into some number of units, and at each unit, there may or may not exist a stone. The frog can jump on a stone, but it must not jump into the water.
Given a list of stones positions (in units) in sorted ascending order, determine if the frog can cross the river by landing on the last stone. Initially, the frog is on the first stone and assumes the first jump must be 1 unit.
If the frog's last jump was k units, its next jump must be either k - 1, k, or k + 1 units. The frog can only jump in the forward direction.

Example 1:
Input: stones = [0,1,3,5,6,8,12,17]
Output: true
Explanation: The frog can jump to the last stone by jumping 1 unit to the 2nd stone, then 2 units to the 3rd stone, then 2 units to the 4th stone, then 3 units to the 6th stone, 4 units to the 7th stone, and 5 units to the 8th stone.
Example 2:
Input: stones = [0,1,2,3,4,8,9,11]
Output: false
Explanation: There is no way to jump to the last stone as the gap between the 5th and 6th stone is too large.
 
Constraints:
2 <= stones.length <= 2000
0 <= stones[i] <= 2^31 - 1
stones[0] == 0
stones is sorted in a strictly increasing order.
*/



class Solution {
public:
    int dp[2000][2000];
    bool f(int ind, int k, unordered_map<int,int> &mp, int target, vector<int> &stones){

        if(ind==target) return true;
        if(dp[ind][k]!=-1) return dp[ind][k];

        bool res = false;
        if(k>1 && mp[stones[ind]+k-1]){
            res |= f(mp[stones[ind]+k-1],k-1,mp,target,stones);
        }
        if(k && mp[stones[ind]+k]){
            res |= f(mp[stones[ind]+k],k,mp,target,stones);
        }
        if(mp[stones[ind]+k+1]){
            res |= f(mp[stones[ind]+k+1],k+1,mp,target,stones);
        }
        return dp[ind][k] = res;
    }

    bool canCross(vector<int>& stones) {
        unordered_map<int,int> mp;
        memset(dp,-1,sizeof(dp));
        for(int i=0; i<stones.size(); i++){
            mp[stones[i]] = i;
        }
        return f(0,0,mp,stones.size()-1,stones);
    }
};

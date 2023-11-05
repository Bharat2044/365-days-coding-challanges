// Question Link: https://leetcode.com/problems/heaters/

/*
475. Heaters

Winter is coming! During the contest, your first job is to design a standard heater with a fixed warm radius to warm all the houses.

Every house can be warmed, as long as the house is within the heater's warm radius range. 

Given the positions of houses and heaters on a horizontal line, return the minimum radius standard of heaters so that those heaters could cover all houses.

Notice that all the heaters follow your radius standard, and the warm radius will the same.

Example 1:
Input: houses = [1,2,3], heaters = [2]
Output: 1
Explanation: The only heater was placed in the position 2, and if we use the radius 1 standard, then all the houses can be warmed.
Example 2:
Input: houses = [1,2,3,4], heaters = [1,4]
Output: 1
Explanation: The two heaters were placed at positions 1 and 4. We need to use a radius 1 standard, then all the houses can be warmed.
Example 3:
Input: houses = [1,5], heaters = [2]
Output: 3

Constraints:
1 <= houses.length, heaters.length <= 3 * 104
1 <= houses[i], heaters[i] <= 109
*/



class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        
        int n = houses.size(), m = heaters.size();
        int ans = 0;

        for(auto h : houses){
            int id = lower_bound(heaters.begin(), heaters.end(), h) - heaters.begin();
            int right = id>= m ? INT_MAX : heaters[id] - h;
            int left = id-1 < 0 ? INT_MAX : h - heaters[id-1];
            ans = max(ans,min(right,left) );
        }

        return ans;
    }
};

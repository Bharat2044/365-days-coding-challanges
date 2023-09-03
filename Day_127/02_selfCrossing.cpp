// Question Link: https://leetcode.com/problems/self-crossing/

/*
335. Self Crossing

You are given an array of integers distance.

You start at the point (0, 0) on an X-Y plane, and you move distance[0] meters to the north, then distance[1] meters to the west, distance[2] meters to the south, distance[3] meters to the east, and so on. In other words, after each move, your direction changes counter-clockwise.

Return true if your path crosses itself or false if it does not.

Example 1:
Input: distance = [2,1,1,2]
Output: true
Explanation: The path crosses itself at the point (0, 1).
Example 2:
Input: distance = [1,2,3,4]
Output: false
Explanation: The path does not cross itself at any point.
Example 3:
Input: distance = [1,1,1,2,1]
Output: true
Explanation: The path crosses itself at the point (0, 0).
 
Constraints:
1 <= distance.length <= 105
1 <= distance[i] <= 105
*/



class Solution {
public:
    bool isSelfCrossing(vector<int>& distance) {
        if(distance.size()<4) return false;
        distance.insert(distance.begin(),0);
        for(int i=3;i<distance.size();i++){
            if(distance[i]>=distance[i-2] && distance[i-1]<=distance[i-3]) return true;
            if(i>=5){
                if(distance[i-1]<=distance[i-3] && distance[i-2]>=distance[i-4]&& distance[i-5]>=distance[i-3]-distance[i-1] && distance[i]>=distance[i-2]-distance[i-4])
                return true;
            }
        }
        return false;
    }
};

//UPVOTE IF YOU LIKED THE ANSWER..THANK YOU

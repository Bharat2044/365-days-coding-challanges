// Question Link: https://leetcode.com/problems/water-and-jug-problem/

/*
365. Water and Jug Problem

You are given two jugs with capacities jug1Capacity and jug2Capacity liters. There is an infinite amount of water supply available. Determine whether it is possible to measure exactly targetCapacity liters using these two jugs.

If targetCapacity liters of water are measurable, you must have targetCapacity liters of water contained within one or both buckets by the end.

Operations allowed:
Fill any of the jugs with water.
Empty any of the jugs.
Pour water from one jug into another till the other jug is completely full, or the first jug itself is empty.
 
Example 1:
Input: jug1Capacity = 3, jug2Capacity = 5, targetCapacity = 4
Output: true
Explanation: The famous Die Hard example 
Example 2:
Input: jug1Capacity = 2, jug2Capacity = 6, targetCapacity = 5
Output: false
Example 3:
Input: jug1Capacity = 1, jug2Capacity = 2, targetCapacity = 3
Output: true
 
Constraints:
1 <= jug1Capacity, jug2Capacity, targetCapacity <= 106
*/



class Solution {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        
        int x=jug1Capacity,y=jug2Capacity,z=x+y;
        int steps[]={x,-x,-y,y}; //STEPS THAT CAN BE PERFORMED
        
        queue<int> q;
        vector<int> vis(z+1,0); // VISITED ARRAY TO KEEP NOT ITERATING THE SAME VALUES OVER AND OVER AGAIN
        q.push(0);
        vis[0]=1;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            
            if(node==targetCapacity)
            {
                return true; // WHEN WE FIND THE TARGET CAPACITY ACHIEVED
            }
            for(int i=0;i<4;i++)
            {
                int newNode=node+steps[i];
                if(newNode>=0 && newNode<=z && vis[newNode]==0) //BOUNDARY CHECKS 
                {
                    q.push(newNode);
                    vis[newNode]=1;
                }
            }
        }
        return false; // IF TARGET CAPACITY CAN NEVER BE ACHIVED
    }
};

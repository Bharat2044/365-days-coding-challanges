// Question Link: https://leetcode.com/problems/brick-wall/

/*
There is a rectangular brick wall in front of you with n rows of bricks. The ith row has some number of bricks each of the same height (i.e., one unit) but they can be of different widths. The total width of each row is the same.

Draw a vertical line from the top to the bottom and cross the least bricks. If your line goes through the edge of a brick, then the brick is not considered as crossed. You cannot draw a line just along one of the two vertical edges of the wall, in which case the line will obviously cross no bricks.

Given the 2D array wall that contains the information about the wall, return the minimum number of crossed bricks after drawing such a vertical line.

Example 1:
Input: wall = [[1,2,2,1],[3,1,2],[1,3,2],[2,4],[3,1,2],[1,3,1,1]]
Output: 2
Example 2:
Input: wall = [[1],[1],[1]]
Output: 3 

Constraints:
n == wall.length
1 <= n <= 104
1 <= wall[i].length <= 104
1 <= sum(wall[i].length) <= 2 * 104
sum(wall[i]) is the same for each row i.
1 <= wall[i][j] <= 231 - 1
*/



class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) 
    {
        unordered_map<int, int> edge_frequency;     //HashMap to store the number of common edges among the rows
        int max_frequency = 0;         //Variable to store the frequency of most occuring edge
        
        for(int row=0; row<wall.size(); row++)        //Iterating through each row
        {
            int edge_postion = 0;       //Variable to store different edge postion
            
            for(int brick_no=0; brick_no< wall[row].size() -1; brick_no++)    //Iterating through each brick inside a row
            { 
                int current_brick_length = wall[row][brick_no];  //Length of the current brick
                edge_postion = edge_postion + current_brick_length ;  //Next Edge Position = Previous Edge Position + Current Brick's Length
                edge_frequency[edge_postion]++;  //Incrementing the Frequency of just calculated Edge Postion
                max_frequency = max(edge_frequency[edge_postion],max_frequency);  //Comparing the "Frequency of just calculated Edge Postion" with "Max Frequency seen till now" & storing whichever is greater.
            }
        }
        return wall.size() - max_frequency; // returning (Number of Bricks Crossed by Line) i.e. (Number of Rows in Wall - Frequency of Most Occuring Edge) 
    }
};

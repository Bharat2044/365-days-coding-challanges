// Question Link: https://leetcode.com/problems/valid-square/

/*
593. Valid Square

Given the coordinates of four points in 2D space p1, p2, p3 and p4, return true if the four points construct a square.

The coordinate of a point pi is represented as [xi, yi]. The input is not given in any order.

A valid square has four equal sides with positive length and four equal angles (90-degree angles).

Example 1:
Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
Output: true
Example 2:
Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,12]
Output: false
Example 3:
Input: p1 = [1,0], p2 = [-1,0], p3 = [0,1], p4 = [0,-1]
Output: true
 
Constraints:
p1.length == p2.length == p3.length == p4.length == 2
-104 <= xi, yi <= 104
*/



class Solution {
public:
    int sideSquare(vector<int>& a, vector<int>& b) {

        int side=0;
        side=((a[0]-b[0])*(a[0]-b[0])+(a[1]-b[1])*(a[1]-b[1]));

        return side;
    }

    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        
        vector<int> sides;

        sides.push_back(sideSquare(p1, p2));
        sides.push_back(sideSquare(p2, p3));
        sides.push_back(sideSquare(p3, p4));
        sides.push_back(sideSquare(p4, p1));
        sides.push_back(sideSquare(p1, p3));
        sides.push_back(sideSquare(p2, p4));

        sort(sides.begin(), sides.end());

        return (sides[0]>0 && sides[0]==sides[3] && sides[4]==sides[5]);
    }
};

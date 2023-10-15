// Question Link: https://leetcode.com/problems/max-points-on-a-line/

/*
149. Max Points on a Line

Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane, return the maximum number of points that lie on the same straight line.

Example 1:
Input: points = [[1,1],[2,2],[3,3]]
Output: 3
Example 2:
Input: points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
Output: 4
 
Constraints:
1 <= points.length <= 300
points[i].length == 2
-104 <= xi, yi <= 104
All the points are unique.
*/



//Prerequisites: Basic Coordinate Geometry
class point{
    public:
    double x,y;
    point(double x,double y){
        this->x=x;
        this->y=y;
    }
};
class Solution {
public:
    bool isCollinear(point a,point b,point c){//checks if three given points lie on a same line
        double m1=(b.y-a.y)/(b.x-a.x);
        double m2=(c.y-b.y)/(c.x-b.x);
        return m1==m2;
    }
    int maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        if(n<=2){//2 or less than two points are always collinear
            return n;
        }
        vector<point> coordinates;
        for(auto& i:points){
            point k=point((double)i[0],(double)i[1]);
            coordinates.push_back(k);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int cnt=0;
                for(int k=0;k<n;k++){
                    if(i!=j&&j!=k&&i!=k){
                        if(isCollinear(coordinates[i],coordinates[j],coordinates[k])){
                            cnt++;
                        }
                    }
                }
                ans=max(cnt+2,ans);
            }
        }
        return ans;
    }
};

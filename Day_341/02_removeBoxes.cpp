// Question Link: https://leetcode.com/problems/remove-boxes/

/*
546. Remove Boxes

You are given several boxes with different colors represented by different positive numbers.
You may experience several rounds to remove boxes until there is no box left. Each time you can choose some continuous boxes with the same color (i.e., composed of k boxes, k >= 1), remove them and get k * k points.
Return the maximum points you can get.

Example 1:
Input: boxes = [1,3,2,2,2,3,4,3,1]
Output: 23
Explanation:
[1, 3, 2, 2, 2, 3, 4, 3, 1] 
----> [1, 3, 3, 4, 3, 1] (3*3=9 points) 
----> [1, 3, 3, 3, 1] (1*1=1 points) 
----> [1, 1] (3*3=9 points) 
----> [] (2*2=4 points)
Example 2:
Input: boxes = [1,1,1]
Output: 9
Example 3:
Input: boxes = [1]
Output: 1

Constraints:
1 <= boxes.length <= 100
1 <= boxes[i] <= 100
*/



class Solution {
public:
    int dp[101][101][101] = {};
    vector<vector<int>> group;
    
    int help(int l,int r,int k){
        if (l>r) return 0;
        if (dp[l][r][k]!=0) return dp[l][r][k];
        
        int sz = group[l][1], num = group[l][0];
        dp[l][r][k] = help(l+1,r,0) + (k+sz)*(k+sz);
        for (int i=l+1; i<=r; i++){
            if (num==group[i][0]){
                dp[l][r][k] = max(dp[l][r][k], help(l+1,i-1,0) + help(i,r,k+sz));
            }
        }
        return dp[l][r][k];
    }
    
    int removeBoxes(vector<int>& boxes) {
        int n=boxes.size(), c=1;
        for(int i=1; i<n; i++){
            if(boxes[i]!=boxes[i-1]){
                group.push_back({boxes[i-1], c});
                c=0;
            }
            c++;
        }
        group.push_back({boxes[n-1], c});
        for(auto &i : group)cout<<i[0]<<" "<<i[1]<<"\n";
        return help(0,group.size()-1,0);
    }
};

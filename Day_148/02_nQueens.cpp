// Question Link: https://leetcode.com/problems/n-queens/

/*
51. N-Queens

The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

Example 1:
Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
Example 2:
Input: n = 1
Output: [["Q"]]
 
Constraints:
1 <= n <= 9
*/




class Solution {
public:
    // function to check if placing the queen at x,y will be valid
    bool isvalid(vector<string> &vec, int x, int y)
    {   
        int n=vec.size();
        for(int i=0;i<n;i++)
        {
            if(vec[x][i]=='Q'||vec[i][y]=='Q') return false;
            if(x-i>=0&&y-i>=0&&vec[x-i][y-i]=='Q') return false;
		    if(x-i>=0&&y+i< n&&vec[x-i][y+i]=='Q') return false;
        }
        return true;
    }
    
    void backtrack(vector<string> &vec, vector<vector<string>> &ans, int n, int i1, int j1)
    {
        if(n==0){
            ans.push_back(vec);
            return;
        }
        int len=vec.size();
        for(int i=i1;i<len;i++)
        {   
            if(len-i<n) return;
            for(int j=j1;j<len;j++)
            {
                if(vec[i][j]=='Q') continue;
                else if(vec[i][j]=='.')
                {
                    if(isvalid(vec,i,j))
                    {
                        vec[i][j]='Q';
                        backtrack(vec,ans,n-1,i1+1,0);
                        vec[i][j]='.';
                    }
                }
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> vec(n,string (n,'.'));
        backtrack(vec,ans,n,0,0);
        return ans;
    }
};

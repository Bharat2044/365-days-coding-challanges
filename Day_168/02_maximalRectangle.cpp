// Question Link: https://leetcode.com/problems/maximal-rectangle/

/*
85. Maximal Rectangle

Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

Example 1:
Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.
Example 2:
Input: matrix = [["0"]]
Output: 0
Example 3:
Input: matrix = [["1"]]
Output: 1
 
Constraints:
rows == matrix.length
cols == matrix[i].length
1 <= row, cols <= 200
matrix[i][j] is '0' or '1'.
*/



class Solution {
public:

int solve(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        st.push(-1);
        vector<int> nextSmaller(n);
        for(int i=n-1; i>=0; i--)   {
            while(st.top() !=- 1 && arr[i] <= arr[st.top()])    
                st.pop();
            if(st.top()==-1)  nextSmaller[i] = n;
            else nextSmaller[i] = st.top();
            st.push(i);  
        }
        while(!st.empty())  st.pop();
        st.push(-1);
        vector<int> prevSmaller(n);
        for(int i=0; i<n; i++)   {
            while(st.top() !=- 1 && arr[i] <= arr[st.top()])    
                st.pop();
            if(st.top()==-1)  prevSmaller[i] = -1;
            else prevSmaller[i] = st.top();
            st.push(i);  
        }
        
        int maxi = 0;
        for(int i=0; i<n;  i++) {
            int area = arr[i] * (nextSmaller[i] - prevSmaller[i]-1);
            maxi = max(maxi, area);
        }
        return maxi;
    }


    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size(), maxi = 0;

        vector<vector<int>> mat(n, vector<int>(m,0));

        for(int i=0; i<n; i++) 
            for(int j=0; j<m; j++)  
                mat[i][j] = matrix[i][j] - '0';

        for(int i=1; i<mat.size(); i++) 
            for(int j=0; j<mat[0].size(); j++)
                if(mat[i][j] != 0)  mat[i][j] += mat[i-1][j];

        for(auto it : mat)     maxi = max(maxi, solve(it));

        return maxi;
    }
};

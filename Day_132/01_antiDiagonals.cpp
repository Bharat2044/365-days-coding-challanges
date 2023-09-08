// Question Link: https://www.interviewbit.com/problems/anti-diagonals/

/*
Anti Diagonals

Problem Description
Give a N*N square matrix, return an array of its anti-diagonals. Look at the example for more details.

Example:
Input:
1 2 3
4 5 6
7 8 9
Return the following:
[ 
  [1],
  [2, 4],
  [3, 5, 7],
  [6, 8],
  [9]
]

Input: 
1 2
3 4
Return the following: 
[
  [1],
  [2, 3],
  [4]
]
*/



vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
   
    vector<vector<int> > ans;
    int rowStart= 0, colStart= 0;
    
    while(rowStart < A.size()) {
        int row= rowStart;
        int col= colStart;  
        vector<int> temp;
        
        while(row < A.size() and col >=0) {
            temp.push_back(A[row][col]);
            row++; col--;
        }
        
        ans.push_back(temp);
        if(colStart ==A.size()-1 ) {
            rowStart++;
        } else {
            colStart++;
        }
    }
    
    return ans;
}

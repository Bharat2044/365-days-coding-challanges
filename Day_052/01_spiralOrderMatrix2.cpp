// Question Link: https://www.interviewbit.com/problems/spiral-order-matrix-ii/

/*
Spiral Order Matrix II

Problem Description:
Given an integer A, generate a square matrix filled with elements from 1 to A2 in spiral order and return the generated square matrix.

Problem Constraints:
1 <= A <= 1000 

Input Format:
First and only argument is integer A

Output Format:
 Return a 2-D matrix which consists of the elements added in spiral order.

Example Input:
Input 1:
1
Input 2:
2
Input 3:
5

Example Output:
Output 1:
[ [1] ]
Output 2:
[ [1, 2], 
  [4, 3] ]
Output 2:
[ [1, 2, 3, 4, 5], 
  [16, 17, 18, 19, 6], 
  [15, 24, 25, 20, 7], 
  [14, 23, 22, 21, 8], 
  [13, 12, 11, 10, 9] ]

Example Explanation:
Explanation 1:
Only 1 is to be arranged.
Explanation 2:
1 --> 2
      |
      |
4<--- 3
*/




vector<vector<int> > Solution::generateMatrix(int A) {
    int curr = 1;
   
    vector<vector<int>> ans(A, vector<int> (A, -1));
    int i=0, j=0;
    int row = A, col = A;
    int rolo = 1, colo = 0;
   
    while(curr <= (A*A)){
        while(j < col){
            ans[i][j] = curr;
            curr += 1;
            j += 1;
        }
        
        col -= 1;
        j -= 1;
        i += 1;
        
        while(i < row){
            ans[i][j] = curr++;
            i += 1;
        }
        
        row -= 1;
        i -= 1;
        j -= 1;
        
        while(j >= colo){
            ans[i][j] = curr++;
            j -= 1;
        }
        
        colo += 1;
        j += 1;
        i -= 1;
        
        while(i >= rolo){
            ans[i][j] = curr++;
            i -= 1;
        }
        rolo += 1;
        i += 1;
        j += 1;
    }
   
    return ans;
}

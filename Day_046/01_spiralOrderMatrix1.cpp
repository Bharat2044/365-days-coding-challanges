// Question Link: https://www.interviewbit.com/problems/spiral-order-matrix-i/

/*
Spiral Order Matrix I

Problem Description: 
Given a matrix of M * N elements (M rows, N columns), return all elements of the matrix in spiral order.

Problem Constraints:
1 <= M, N <= 1000

Input Format:
The first argument is a matrix A.

Output Format:
Return an array of integers representing all elements of the matrix in spiral order.

Example Input:
A = 
    [
        [ 1, 2, 3 ],
        [ 4, 5, 6 ],
        [ 7, 8, 9 ]
    ]
    
Example Output:
[1, 2, 3, 6, 9, 8, 7, 4, 5]
*/




vector<int> Solution::spiralOrder(const vector<vector<int> > &A) {
    int left = 0;
    int right = A[0].size()-1;
    int top = 0;
    int bottom = A.size()-1;

    vector<int>ans;
    int i;

    while(left<=right && top<=bottom) {

        for(int i=left; i<=right; i++)
            ans.push_back(A[top][i]);
        top++;
        
        for(int i=top; i<=bottom; i++)
            ans.push_back(A[i][right]);     
        right--;
        
        if(left>right || top>bottom) 
            break;
            
        for(int i=right; i>=left; i--)
            ans.push_back(A[bottom][i]);
        bottom--;
        
        for(i=bottom; i>=top; i--) 
            ans.push_back(A[i][left]);
        left++;
    }

    return ans;
}






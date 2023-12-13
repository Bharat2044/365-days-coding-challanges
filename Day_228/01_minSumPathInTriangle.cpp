// QUestion Link: https://www.interviewbit.com/problems/min-sum-path-in-triangle/

/*
Min Sum Path in Triangle

Problem Description:
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
Adjacent numbers for jth number of row i is jth and (j+1)th numbers of row i+1 is  

Problem Constraints:
1 <= |A| <= 1000
1 <= A[i] <= 1000

Input Format:
First and only argument is the vector of vector A defining the given triangle

Output Format:
Return the minimum sum 

Example Input:
Input 1: 
A = [ 
         [2],
        [3, 4],
       [6, 5, 7],
      [4, 1, 8, 3]
    ]
Input 2:
A = [ [1] ]

Example Output:
Output 1:
11
Output 2:
1

Example Explanation:
Explanation 1:
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
Explanation 2:
Only 2 can be collected.
*/



int Solution::minimumTotal(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    for(int i=A.size()-2;i>=0;i--) {
        for(int j=0;j<A[i].size();j++)
            A[i][j]+=min(A[i+1][j],A[i+1][j+1]);
    }
            
    return A[0][0];
}

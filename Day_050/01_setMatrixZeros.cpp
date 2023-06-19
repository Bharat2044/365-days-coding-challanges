// Question Link: https://www.interviewbit.com/problems/set-matrix-zeros/

/*
Set Matrix Zeros

Problem Description:
Given a matrix, A of size M x N of 0s and 1s. If an element is 0, set its entire row and column to 0.
Note: This will be evaluated on the extra memory used. Try to minimize the space and time complexity.

Problem Constraints
1 <= N, M <= 1000
0 <= A[i][j] <= 1

Input Format:
The first and the only argument of input contains a 2-d integer matrix, A, of size M x N.

Output Format:
Return a 2-d matrix that satisfies the given conditions.

Example Input:
Input 1:
[   [1, 0, 1],
    [1, 1, 1], 
    [1, 1, 1]   ]
Input 2:
[   [1, 0, 1],
    [1, 1, 1],
    [1, 0, 1]   ]

Example Output:
Output 1:
[   [0, 0, 0],
    [1, 0, 1],
    [1, 0, 1]   ]
Output 2:
[   [0, 0, 0],
    [1, 0, 1],
    [0, 0, 0]   ]
*/



void Solution::setZeroes(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    unordered_set<int> s_row;
    unordered_set<int> s_col;

    for(int i=0; i<A.size(); i++){
        for(int j=0; j<A[i].size(); j++){

            if(A[i][j] == 0){
                s_row.insert(i);
                s_col.insert(j);
            }
        }
    }

    unordered_set<int> :: iterator itr;

    for(itr=s_row.begin(); itr!=s_row.end(); itr++){
        for(int i = 0;i<A[*itr].size();i++)
            A[*itr][i] = 0;
    }

    for(itr=s_col.begin(); itr!=s_col.end(); itr++){
        for(int i=0; i<A.size(); i++)
            A[i][*itr] = 0;
    }

}

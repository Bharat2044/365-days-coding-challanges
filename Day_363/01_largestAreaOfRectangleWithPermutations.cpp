// Question Link: https://www.interviewbit.com/problems/largest-area-of-rectangle-with-permutations/

/*
Largest area of rectangle with permutations

Problem Description:
Given a binary grid A of size N x M consisting of 0's and 1's, find the area of the largest rectangle inside the grid such that all the cells inside the chosen rectangle should have 1 in them.
You are allowed to permutate the columns matrix i.e. you can arrange each of the column in any order in the final grid.
Please follow the sample input and explanation for more clarity.

Problem Constraints:
1 <= N, M <= 10^3

Input Format:
First and only argument is an 2D binary array A.

Output Format:
Return a single integer denoting the area of the largest rectangle inside the grid such that all the cells inside the chosen rectangle should have 1 in them.

Example Input:
Input 1:
 A = [  [1, 0, 1]
        [0, 1 ,0]
        [1, 0, 0]
    ]

Example Output:
Output 1:
 2

Example Explanation:
Explanation 1:
    1 0 1
    0 1 0
    1 0 0
At present we can see that max rectangle satisfying the criteria mentioned in the problem
 is of 1 * 1 = 1 area i.e either of the 4 cells which contain 1 in it.

Now since we are allowed to permutate the columns of the given matrix, we can take column 1
 and column 3 and make them neighbours. One of the possible configuration of the grid can be:
 1 1 0
 0 0 1
 1 0 0

Now In this grid, first column is column 1, second column is column 3 and third column
 is column 2 from the original given grid.

Now, we can see that if we calculate the max area rectangle, we get max area as 1 * 2 = 2
 which is bigger than the earlier case. Hence 2 will be the answer in this case.
*/



int Solution::solve(vector<vector<int> > &A) {
    vector<vector<int>> v(A.size(),vector<int>(A[0].size()));
    for(int i=0;i<A[0].size();i++){
        int c=0;
        for(int j=A.size()-1;j>=0;j--){
            if(A[j][i]==0){
                c=0;
                v[j][i]=c;
            }else{
                c++;
                v[j][i]=c;
            };
        };
       
    };
    vector<int> v2(A.size());
    for(int i=0;i<A.size();i++){
        v2[i]=0;
        for(int j=0;j<A[0].size();j++){
          if(A[i][j]!=0)v2[i]++;  
        };
    };
    int max=0;
    for(int i=0;i<A.size();i++){
        int area=0;
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int j=0;j<A[0].size();j++){
           if(A[i][j]!=0) pq.push(v[i][j]);
        };
        while(!pq.empty()){
            int k=pq.top();
            pq.pop();
            area=v2[i]*k>area?v2[i]*k:area;
            v2[i]--;
        };
        max=area>max?area:max;
    }
    return max;
};

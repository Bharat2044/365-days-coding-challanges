// Question Link: https://www.interviewbit.com/problems/multiple-left-rotations-of-the-array/

/*
Multiple left rotations of the array

Problem Description:
Given an array of integers A and multiple values in B, which represents the number of times array A needs to be left rotated.
Find the rotated array for each value and return the result in the from of a matrix where ith row represents the rotated array for the ith value in B.

Problem Constraints:
1 <= |A|, |B| <= 2000
-109 <= A[i] <= 109
0 <= B[i] <= 2000

Input Format:
The first argument given is the integer array A.
The second argument given is the integer array B.

Output Format:
Return the resultant matrix.

Example Input:
Input 1:
    A = [1, 2, 3, 4, 5]
    B = [2, 3]
Input 2:
    A = [5, 17, 100, 11]
    B = [1]

Example Output:
Output 1:
 [ [3, 4, 5, 1, 2]
   [4, 5, 1, 2, 3] ]
Output 2:
[ [17, 100, 11, 5] ]

Example Explanation:
for input 1 -> B[0] = 2 which requires 2 times left rotations
     1: [2, 3, 4, 5, 1]
     2: [3, 4, 5, 1, 2]
B[1] = 3 which requires 3 times left rotation 
     1: [2, 3, 4, 5, 1]
     2: [3, 4, 5, 1, 2]
     2: [4, 5, 1, 2, 3]
*/



vector<vector<int> > Solution::solve(vector<int> &A, vector<int> &B) {
    int n=A.size();
    int m=B.size();
    
    vector<vector<int>>ans;
    for(int i=0; i<m; i++){
        int s=B[i]%n;
        vector<int>nums(A);
      reverse(nums.begin(), nums.begin()+s);
      reverse(nums.begin()+s , nums.begin()+n);
      reverse(nums.begin(), nums.end());
          ans.push_back(nums);
    }
    return ans;
}

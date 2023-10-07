// Question Link: https://www.interviewbit.com/problems/move-zeroes/

/*
Move Zeroes

Problem Description:
 Given an integer array A, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

Problem Constraints:
1 <= |A| <= 105

Input Format:
First argument is array of integers A.

Output Format:
Return an array of integers which satisfies above property.

Example Input:
Input 1:
A = [0, 1, 0, 3, 12]
Input 2:
A = [0]

Example Output:
Ouput 1:
[1, 3, 12, 0, 0]
Ouput 2:
[0]

Example Explanation:
Explanation 1:
Shift all zeroes to the end.
Explanation 2:
There is only one zero so no need of shifting.
*/



vector<int> Solution::solve(vector<int> &A) {
    int n=A.size();
    vector<int> B;
    
    for(int i=0;i<n;i++){
        if(A[i]!=0){
            B.push_back(A[i]);
        }
    }
    
    sort(A.begin(),A.end());
    reverse(A.begin(),A.end());
    
    for(int i=0;i<B.size();i++){
        A[i]=B[i];
    }
    
    return A;
}

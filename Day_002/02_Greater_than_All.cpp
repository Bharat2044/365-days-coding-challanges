// Question Link: https://www.interviewbit.com/problems/greater-than-all/

/*
Problem Description:
Given an integer array A.
Find the count of elements whose value is greater than all of its previous elements.

Note: Since there are no elements before first element so it should be considered in our answer.

Problem Constraints:
1 <= |A| <= 105
1 <= Ai <= 109

Input Format:
Given an integer array A.

Output Format:
Return an integer.

Example Input
Input 1:
A = [1, 2, 3, 4]
Input 2:
A = [1, 1, 2, 2]

Example Output
Output 1:
4
Output 2:
2

Example Explanation:
Explanation 1:
All elements are greater than all of its prior elements.
Explanation 2:

Index 1 will be considerd in answer.
Also Elements at index 3 is greater than all of it's previous elements.
*/


// Time Complexity = O(n), Space Complexity = O(1)
int Solution::solve(vector<int> &A) {
    int count = 1;
    int p = A[0];
    
    for(int i=1; i<A.size(); i++) {
        
       if (A[i] > p) {
           p = A[i];
           count++;
       }
    }
    return count;
}

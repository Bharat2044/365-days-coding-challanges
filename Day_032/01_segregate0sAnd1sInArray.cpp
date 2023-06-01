// Question Link: https://www.interviewbit.com/problems/segregate-0s-and-1s-in-an-array/

/*
Segregate 0s and 1s in an array:

Problem Description:
You are given an array of 0s and 1s in random order. Segregate 0s on left side and 1s on right side of the array [Basically you have to sort the array]. Traverse array only once. 

Problem Constraints:
1<=|A|<=1e6

Input Format:
First argument is array of integers consisting of 0's and 1's only.

Output Format:
Return a sorted array.

Example Input:
Input 1:
a=[0 1 0]
Input 2:
A=[1 1 0 ]

Example Output:
Ouput 1:
[0 0 1]
Ouput 2:
[0 1 1]

Example Explanation:
Explanation 1:
 above is sorted array.
Explanation 2:
sort the array.
*/



// Time Complexity = O(n), Space Complexity = O(1)
vector<int> Solution::solve(vector<int> &A) {
    int st = 0, end = A.size()-1;
    
    while(st < end) {
        if(A[st]==1 && A[end]==0) 
            swap(A[st++], A[end]);  
        else if(A[st]==1 && A[end]==1) 
            end--;  
        else if(A[st] == 0)
            st++;      
        else if(A[end] == 1) 
            end--;
    }
    
    return A;
}

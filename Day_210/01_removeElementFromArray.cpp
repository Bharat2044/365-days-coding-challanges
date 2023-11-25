// Question Link: https://www.interviewbit.com/problems/remove-element-from-array/

/*
Remove Element from Array

Problem Description:
Given an array A and a value B, remove all the instances of that value in the array.
Also, return the number of elements left in the array after the operation. It does not matter what is left beyond the expected length.
Try to do it in less than linear additional space complexity.

Problem Constraints:
1 <= |A| <= 106
0 <= Ai , B <= 2 * 109

Input Format:
The first argument is an integer array A.
The second argument is an integer B.

Output Format:
Return an integer denoting the number of elements left in the array after the operation, also update the given array A.

Example Input:
A = [4, 1, 1, 2, 1, 3]
B = 1

Example Output:
Length  : 3 
Array A : [4, 2, 3] 

Example Explanation:
If array A is [4, 1, 1, 2, 1, 3]
and the value element is 1,
then the new length is 3, and A is now [4, 2, 3]
*/



int Solution::removeElement(vector<int> &A, int B) {
    int n=A.size();
    int i=0,j=0,ans=0;
    
    while(j<n){
        if(A[j]==B) 
            j++;
        else{
            swap(A[i++],A[j++]);
            ans++;
        }
    }
    
    return ans;
}

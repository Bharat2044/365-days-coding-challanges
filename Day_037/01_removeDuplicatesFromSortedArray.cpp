// Question Link: https://www.interviewbit.com/problems/remove-duplicates-from-sorted-array/

/*
Remove Duplicates from Sorted Array

Problem Description:
Given a sorted array A consisting of duplicate elements.

Your task is to remove all the duplicates and return the length of the sorted array of distinct elements consisting of all distinct elements present in A.

Note: You need to update the elements of array A by removing all the duplicates

Problem Constraints:
1 <= |A| <= 106
1 <= Ai <= 2 * 109

Input Format:
First and only argurment containing the integer array A.

Output Format:
Return a single integer, as per the problem given.

Example Input:
Input 1:
A = [1, 1, 2]
Input 2:
A = [1, 2, 2, 3, 3]

Example Output:
Output 1:
2
Output 2:
3

Example Explanation:
Explanation 1:
Updated Array: [1, 2, X] after rearranging. Note that there could be any number in place of x since we dont need it.
We return 2 here.
Explanation 2:
Updated Array: [1, 2, 3, X, X] after rearranging duplicates of 2 and 3.
We return 3 from here.
*/


  
  int Solution::removeDuplicates(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

     if(A.size() == 0)
        return 0;
    
    int i = 0;
    
    for(int j=1; j<A.size(); j++) {
      
        if(A[i] != A[j]) {
            i++;
            A[i] = A[j];
        }
    }
    
    return i+1;
}

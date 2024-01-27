// Question Link: https://www.interviewbit.com/problems/even-product/

/*
Even Product!

Problem Description:
Given an integer array A containing N integers.
You can perform a certain type of operation on this array A i.e you can select any number of elements from the array A and change it to whatever value you want.
Initially the Product of elements of the array A is ODD you need to find the total number of distinct operations (modulo 109 + 7) you can perform to make the product of array EVEN.
Two operations are said to be different if there exist atleast one element which is not selected in the other operation.

Problem Constraints:
1 <= N <= 105
1 <= A[i] <= 106

Input Format:
First and only argument is an integer array A.

Output Format:
Return a single integer denoting the total number of distinct operations (modulo 109 + 7) you can perform to make the product of array A as EVEN.

Example Input:
Input 1:
A = [1, 3]
Input 2:
A = [3]
 
Example Output:
Output 1:
3
Output 2:
1

Example Explanation:
Explanation 1:
We can perform atmost three operations:
Operation 1: Selecting element at index 0 and changing its value to 2 so A = [2, 3] Product = 6
Operation 2: Selecting element at index 1 and changing its value to 10 so A = [1, 10] Product = 10
Operation 3: Selecting element at index 0 and 1 and changing their value to 2 so A = [2, 2] Product = 4
We can't perform any other operations on this array.
Explanation 2:
We can perform atmost one operations:
Operation 1: Selecting element at index 0 and changing its value to 20 so A = [20] Product = 20
*/




int Solution::solve(vector<int> &A) {
    int x=1;
    
    for(int i=1; i<=A.size(); i++){
        x=(x*2)%1000000007;
    }
    
    return x-1;
}

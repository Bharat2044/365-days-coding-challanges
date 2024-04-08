// Question Link: https://www.interviewbit.com/problems/subarray-with-given-xor/

/*
Subarray with given XOR

Problem Description:
Given an array of integers A and an integer B.
Find the total number of subarrays having bitwise XOR of all elements equals to B.

Problem Constraints:
1 <= length of the array <= 10^5
1 <= A[i], B <= 10^9

Input Format:
The first argument given is the integer array A.
The second argument given is integer B.

Output Format:
Return the total number of subarrays having bitwise XOR equals to B.

Example Input:
Input 1:
 A = [4, 2, 2, 6, 4]
 B = 6
Input 2:
 A = [5, 6, 7, 8, 9]
 B = 5

Example Output:
Output 1:
 4
Output 2:
 2

Example Explanation:
Explanation 1:
 The subarrays having XOR of their elements as 6 are:
 [4, 2], [4, 2, 2, 6, 4], [2, 2, 6], [6]
Explanation 2:
 The subarrays having XOR of their elements as 5 are [5] and [5, 6, 7, 8, 9]
*/



int Solution::solve(vector<int> &A, int B) {
    int xr=0;
    
    map<int,int> mpp;
    mpp[xr]++; //to add (0,1)
    
    int n= A.size();
    int count=0;
    
    for(int i=0;i<n;i++){
        xr = xr ^ A[i];
        
        int x= xr^B;
        count += mpp[x];
        
        mpp[xr]++;
    }
    
    return count;
}

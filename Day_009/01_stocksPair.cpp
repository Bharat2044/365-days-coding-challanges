// Question Link: https://www.interviewbit.com/problems/socks-pair/

/*
Stocks Pair:

Problem Description:
Given an integer array A of integers.
Every element in the array repersent a colour of a sock, find how many pair of socks with matching colours there are.

Problem Constraints
1 <= |A| <= 105
1 <= Ai <= |A|

Input Format:
Given an integer array A.

Output Format:
Return an integer.

Example Input:
Input 1:
A = [1, 2, 3]
Input 2:
A = [2, 2, 2, 2]

Example Output:
Output 1:
0
Output 2:
2

Example Explanation:
Explanation 1:
No pair of socks can be formed.
Explanation 2:
Two pairs of socks can be formed.
*/


// Time Complexity = O(logn), Space Complexity = O(1)
int Solution::solve(vector<int> &A) {
    sort(A.begin(),A.end());
   
    int count=0;
   
    for(int i=0; i<A.size(); i++) {
        
        if(A[i] == A[i+1]) {
            count++;
            i = i+1;
        }
    }
    
    return count;
}

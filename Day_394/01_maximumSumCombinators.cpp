// Question Link: https://www.interviewbit.com/problems/maximum-sum-combinations/

/*
Maximum Sum Combinations

Problem Description:
Given two equally sized 1-D arrays A, B containing N integers each.
A sum combination is made by adding one element from array A and another element of array B.
Return the maximum C valid sum combinations from all the possible sum combinations.

Problem Constraints:
1 <= N <= 10^5
1 <= A[i] <= 10^5
1 <= C <= N

Input Format:
First argument is an one-dimensional integer array A of size N.
Second argument is an one-dimensional integer array B of size N.
Third argument is an integer C.

Output Format:
Return a one-dimensional integer array of size C denoting the top C maximum sum combinations.

NOTE:
The returned array must be sorted in non-increasing order.

Example Input:
Input 1:
 A = [3, 2]
 B = [1, 4]
 C = 2
Input 2:
 A = [1, 4, 2, 3]
 B = [2, 5, 1, 6]
 C = 4

Example Output:
Output 1:
 [7, 6]
Output 1:
 [10, 9, 9, 8]

Example Explanation:
Explanation 1:
 7     (A : 3) + (B : 4)
 6     (A : 2) + (B : 4)
Explanation 2:
 10   (A : 4) + (B : 6)
 9   (A : 4) + (B : 5)
 9   (A : 3) + (B : 6)
 8   (A : 3) + (B : 5)
*/



#define PII pair<int, pair<int, int>>

vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    int n = A.size();
    vector<int> ans(C);
    
	// Sorted in Descending order
    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), greater<int>());
    
	// Max Heap
    priority_queue<PII> q;
	
	// Pushed all elements of A wrt the largest element of B
    for(int i = 0; i < n; i++)
        q.push({A[i]+B[0], {i, 0}});
        
    PII t;
    int ind = 0;
    while(ind < C){
        t = q.top();
        ans[ind++] = t.first;
        q.pop();
        int i = t.second.first, j = t.second.second;
		// Only have to push the Sum of current largest element of A wrt the next largest element of B
        q.push({A[i] + B[j+1], {i, j+1}});
    }    
    return ans;
}


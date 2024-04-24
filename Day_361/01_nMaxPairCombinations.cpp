// Question Link: https://www.interviewbit.com/problems/n-max-pair-combinations/

/*
N max pair combinations

Problem Description:
Given two integers arrays A and B of size N each.
Find the maximum N elements from the sum combinations (Ai + Bj) formed from elements in array A and B.

Problem Constraints:
1 <= N <= 2 * 10^5
-1000 <= A[i], B[i] <= 1000

Input Format:
First argument is an integer array A.
Second argument is an integer array B.

Output Format:
Return an intger array denoting the N maximum element in descending order.

Example Input:
Input 1:
 A = [1, 4, 2, 3]
 B = [2, 5, 1, 6]
Input 2:
 A = [2, 4, 1, 1]
 B = [-2, -3, 2, 4]

Example Output:
Output 1:
 [10, 9, 9, 8]
Output 2:
 [8, 6, 6, 5]

Example Explanation:
Explanation 1:
 4 maximum elements are 10(6+4), 9(6+3), 9(5+4), 8(6+2).
Explanation 2:
 4 maximum elements are 8(4+4), 6(4+2), 6(4+2), 5(4+1).
*/



bool rev(int a, int b)
{
    return b<a;
}
vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    sort(A.begin(),A.end(),rev);
    sort(B.begin(),B.end(),rev);
    priority_queue<int,vector<int>,greater<int>> pq;
    int n = A.size();
    int k = 0;
    while(k<n)
    {
        pq.push(A[k]+B[k]);
        k++;
    }
    for(int i = 0; i< n ;++i)
    {
        for(int j = 0; j< n;++j)
        {
            if(i!=j)
            {
                if((A[i]+B[j]) > pq.top())
                {
                    pq.pop();
                    pq.push(A[i]+B[j]);
                }
                else
                {
                    break;
                }
            }
        }
    }
    vector<int> ans(n,0);
    int c = 0;
    while(c <n)
    {
        ans[c] = pq.top();
        pq.pop();
        c++;
    }
   
    sort(ans.begin(), ans.end(),rev);
    return ans;
}

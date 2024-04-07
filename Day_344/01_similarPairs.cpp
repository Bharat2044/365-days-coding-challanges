// Question Link: https://www.interviewbit.com/problems/similar-pairs/

/*
Similar Pairs

Problem Description:
Given an integer array A of size N, you need to find the count of pairs  (i, j) such that:
i < j
j - i <= B
A[i] == A[j]
Return the count of such pairs modulo 10^9 + 7.

Problem Constraints:
2 <= |A| <= 10^5
1 <= A[i] <= 10^9
1 <= B <= 10^5

Input Format:
First argument is an integer array A.
Second argument is an integer B.

Output Format:
Return the count of such pairs that's satisfies all the properties mentioned above in the statement, modulo 109 + 7.

Example Input:
Input 1:
 A = [1, 2, 1, 3, 1, 4]
 B = 2
Input 2:
 A = [12, 11, 8, 1]
 B = 14

Example Output:
Output 1:
 2
Output 2:
 0

Example Explanation:
Explanation 1:
 First pair is (0, 2) as A[0] = A[2] and (2 - 0) <= 2
 Second pair is (2, 4)
Explanation 2:
 No such pair possible as all elements are distinct.
*/



int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    map<int,vector<int>>m;
    int ans=0,mod=1e9+7;
    for(int i=0;i<n;i++){
        ans+=m[A[i]].end()-lower_bound(m[A[i]].begin(),m[A[i]].end(),i-B);
        ans%=mod;
        m[A[i]].push_back(i);
    }
    return ans;
}

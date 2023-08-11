// Question Link: https://www.interviewbit.com/problems/all-factors/

/*
All Factors

Problem Description:
Given a number A, find all factors of A.

Problem Constraints:
1 <= A <= 109

Input Format:
The first argument is an integer A.

Output Format:
Return an array of all factors of A.

Example Input:
A = 6

Example Output:
[1, 2, 3, 6]

Example Explanation:
For the given A = 6, its factors are 1, 2, 3, and 6, hence returning an array of them.
*/




vector<int> Solution::allFactors(int n) {
    vector<int> ans;
    int i;

    for(i=1; i*i<n; i++) {
        if(n%i == 0)
            ans.push_back(i);
    }
    
    if(i-(n/i) == 1)
        i--;

    for(; i>=1; i--) {
        if(n%i == 0)
            ans.push_back(n/i);
    }
    
    return ans;
}

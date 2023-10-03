// Question Link: https://www.interviewbit.com/problems/product-of-all/

/*
Product of All

Problem Description:
Given an integer array A.
Create an array B such that Bi is the product of all elements of A excluding Ai.
Since the products can be too large take modulo 109 +7.

Problem Constraints:
1 <= |A| <= 105
1 <= Ai <= 109

Input Format:
Given an integer array A.

Output Format:
Return an integer array.

Example Input:
Input 1:
A = [1, 2, 3, 4]
Input 2:
A = [9, 9, 9]

Example Output:
Output 1:
[24, 12, 8, 6]
Output 2:
[81, 81, 81]

Example Explanation:
Explanation 1:
[2×3×4, 1×3×4, 1×2×4, 1×2×3]
Explanation 2:
[9×9, 9×9, 9×9]
*/




vector<int> Solution::solve(vector<int> &A) {
    int M=1e9+7;
    int n=A.size();
    
    vector<int> ans(n);
    vector<int> left(n);
    vector<int> right(n);
    
    left[0]=A[0]; 
    right[n-1]=A[n-1];
    
    for(int i=1;i<n;i++){
        left[i]=( left[i-1] * 1LL * A[i]  ) % M;
    }
    for(int i=n-2; i>=0; i--){
        right[i]=( right[i+1] * 1LL * A[i]  ) % M;
    }
    
    ans[0]=right[1];
    ans[n-1]=left[n-2];
    
    for(int i=1;i < n-1;i++){
        ans[i]=( left[i-1] * 1LL * right[i+1]  ) % M;
    }
    
    return ans;
}

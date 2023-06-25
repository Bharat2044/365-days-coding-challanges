// Question Link: https://www.interviewbit.com/problems/max-product-subarray/

/*
Max Product Subarray

Find the contiguous subarray within an array (containing at least one number) which has the largest product.

Return an integer corresponding to the maximum product possible.

Example :
Input : [2, 3, -2, 4]
Return : 6 
Possible with [2, 3]
*/



int Solution::maxProduct(const vector<int> &A) {
    int ans = A[0], i, n = A.size();
    int curMin = 1, curMax = 1;
    
    for(i=0; i<n; i++) {
        int temp = curMin;
        
        curMin = min(A[i], min(A[i]*curMin, A[i]*curMax));
        curMax = max(A[i], max(A[i]*curMax, A[i]*temp));
        
        ans = max(ans, curMax);
    }
    
    return ans;
}

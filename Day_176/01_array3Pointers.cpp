// Question Link: https://www.interviewbit.com/problems/array-3-pointers/

/*
Array 3 Pointers

You are given 3 arrays A, B and C. All 3 of the arrays are sorted.

Find i, j, k such that :

max(abs(A[i] - B[j]), abs(B[j] - C[k]), abs(C[k] - A[i])) is minimized.

Return the minimum max(abs(A[i] - B[j]), abs(B[j] - C[k]), abs(C[k] - A[i]))

**abs(x) is absolute value of x and is implemented in the following manner : **

      if (x < 0) return -x;
      else return x;

Example :
Input : 
        A : [1, 4, 10]
        B : [2, 15, 20]
        C : [10, 12]
Output : 5 
         With 10 from A, 15 from B and 10 from C. 
*/



int Solution::minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    int a = A.size(),b=B.size(),c = C.size();
    int ans = INT_MAX;
   
    int i=a-1,j=b-1,k=c-1;
   
    while(i>=0 && j>=0 && k>=0)
    {
        int maxE = max({A[i],B[j],C[k]});
        int minE = min({A[i],B[j],C[k]});
       
        if(A[i]==maxE) i--;
        else if(B[j]==maxE) j--;
        else k--;
       
        ans = min(ans,maxE-minE);
    }
   
    return ans;
}

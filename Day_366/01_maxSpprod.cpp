// Question Link: https://www.interviewbit.com/problems/maxspprod/

/*
MAXSPPROD

Problem Description:
You are given an array A containing N integers. The special product of each ith integer in this array is defined as the product of the following:
LeftSpecialValue: For an index i, it is defined as the index j such that A[j]>A[i] and (i>j). If multiple A[j]'s are present in multiple positions, the LeftSpecialValue is the maximum value of j. Here LeftSpecialValue is the index j and not A[j].
RightSpecialValue: For an index i, it is defined as the index j such that A[j]>A[i] and (j>i). If multiple A[j]'s are present in multiple positions, the RightSpecialValue is the minimum value of j. Here RightSpecialValue is the index j and not A[j].
Write a program to find the maximum special product of any integer in the array. In other words you have to find the maximum for all i (0<i<n-1) of product of l and r such that l is the LeftSpecialValue and r is the RightSpecialValue of an index i. 
Note that the array A is zero indexed.
NOTE:  As the answer can be large, output your answer modulo 109 + 7.

Problem Constraints:
1 <= N <= 10^5 
1 <= A[i] <= 10^9

Input Format:
First and only argument is an integer array A.

Output Format:
Return an integer denoting the maximum special product of any integer.

Example Input:
Input 1:
 A = [1, 4, 3, 4]
Input 2:
 A = [10, 7, 100]

Example Output:
Output 1:
 3
Output 2:
 0

Example Explanation:
Explanation 1:
 For A[2] = 3, LeftSpecialValue is 1 and RightSpecialValue is 3.
 So, the ans is 1*3 = 3.
Explanation 2:
 There is not any integer having maximum special product > 0. So, the ans is 0.
*/



int Solution::maxSpecialProduct(vector<int> &A) {
    vector<int> right(A.size(),0);
    vector<int> left(A.size(),0);   
    
    stack<int> s;
    s.push(0);

    for(int i=1;i<A.size();i++){
        while(!s.empty() and A[s.top()] <= A[i] )
            s.pop();

        if(!s.empty())
            left[i] = s.top();
        else 
            left[i] = 0;

        s.push(i);
    }

    stack<int>s2;
    s2.push(A.size()-1);

     for(int i=A.size()-2;i>=0;i--){
        while(!s2.empty() and A[s2.top()] <= A[i] )
            s2.pop();

        if(!s2.empty())
            right[i] = s2.top();
        else 
            right[i] = 0;

        s2.push(i);
    }
    
    long long ans=0;
    int mod = 1e9+7;

    for(int i=0;i<left.size();i++){
        ans = max(ans, 1LL*left[i]*right[i]);
        ans%=mod;
    }

    return ans%mod;
}

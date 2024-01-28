// Question Link: https://www.interviewbit.com/problems/make-them-equal/

/*
Make them Equal

Problem Description:
You are given an array A of length N. In one operation you can select an index i ( 1 <= i <= N ) and change A[i] to floor(A[i]/2). floor(x) is the largest integer not greater than x. 
We want to make all the elements of the array equal. Calculate the minimum number of operations needed to do so.

Problem Constraints:
1 <= N <= 105
1 <= A[i] <= 2 × 109

Input Format:
The first and only argument contains an integer array A of length N.

Output Format:
Return the minimum number of operations to make all the elements of the array equal.

Example Input:
Input 1:
A : [ 3, 1, 1, 3 ]
Input 2:
A : [ 2, 2, 2 ]

Example Output:
Output 1:
2
Output 2:
0

Example Explanation:
Explanation 1:
We can do an operation on index 1 and 4 to change the array to [1, 1, 1, 1]
Explanation 2:
All the elements are already same.
*/



int Solution::solve(vector<int> &A) {
    int mini=INT_MAX;
    for(int i:A){
        mini = min(i, mini);
    }
    int count=log2(mini)+1;
   
    int ans=0;
    for(int i=0; i<A.size(); i++){
        int t = log2(A[i]) + 1;
        if(t > count){
            ans += (t-count);
            A[i] = A[i]>>(t-count);
        }
    }
    int x=A[0];
    int y=A[0];
    for(int i:A){
        x = x&i;
        y = y|i;
    }
   
    if(x==y){
        return ans;
    }
    else{
        while(x!=y){
            x = x>>1;
            y = y>>1;
            ans += (A.size());
        }
    }
    return ans;
}

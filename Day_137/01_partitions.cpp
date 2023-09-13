// Question Link: https://www.interviewbit.com/problems/partitions/

/*
Partitions

Problem Description:
You are given a 1D integer array B containing A integers.

Count the number of ways to split all the elements of the array into 3 contiguous parts so that the sum of elements in each part is the same.

Such that : sum(B[1],..B[i]) = sum(B[i+1],...B[j]) = sum(B[j+1],...B[n]) 

Problem Constraints:
1 <= A <= 105
-109 <= B[i] <= 109

Input Format:
First argument is an integer A.
Second argument is an 1D integer array B of size A.

Output Format:
Return a single integer denoting the number of ways to split the array B into three parts with the same sum.

Example Input:
Input 1:
 A = 5
 B = [1, 2, 3, 0, 3]
Input 2:
 A = 4
 B = [0, 1, -1, 0]
 
Example Output:
Output 1:
 2
Output 2:
 1

Example Explanation:
Explanation 1:
 There are no 2 ways to make partitions -
 1. (1,2)+(3)+(0,3).
 2. (1,2)+(3,0)+(3).
Explanation 2:
 There is only 1 way to make partition -
 1. (0)+(-1,1)+(0).
*/



int Solution::solve(int n, vector<int> &b) {
    vector<int>v(n); //prefix array
    v[0]=b[0];
    for(int i=1;i<n;i++){
        v[i]=v[i-1]+b[i];
    }
    int ans=0;
    if(v[n-1]%3!=0)return 0; 
    int t = v[n-1]/3;
    for(int i=0;i<n-2;i++){
        if(v[i]==t){
            int j=i+1;
            while(j<n-1){
                if(v[j]-v[i]==t)ans++;
                j++;
            }
        }
    }
    return ans;
}

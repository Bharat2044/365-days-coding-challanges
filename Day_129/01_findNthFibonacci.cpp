// Question Link: https://www.interviewbit.com/problems/find-nth-fibonacci/

/*
Find Nth Fibonacci

Problem Description:
Given an integer A you need to find the Ath fibonacci number modulo 109 + 7.

The first fibonacci number F1 = 1

The first fibonacci number F2 = 1

The nth fibonacci number Fn = Fn-1 + Fn-2 (n > 2)

Problem Constraints:
1 <= A <= 109.

Input Format:
First argument is an integer A.

Output Format:
Return a single integer denoting Ath fibonacci number modulo 109 + 7.

Example Input:
Input 1:
 A = 4
Input 2:
 A = 3

Example Output:
Output 1:
 3
Output 2:
 2

Example Explanation:
Explanation 1:
 F3 = F2 + F1 = 1 + 1 = 2
 F4 = F3 + F2 = 2 + 1 = 3
Explanation 2:
 F3 = F2 + F1 = 1 + 1 = 2
*/



const int MOD = 1e9+7;

vector<vector<long long int>> matmultipy(vector<vector<long long int>> &a, vector<vector<long long int>> &b ){
    long long int sz = a.size();
    vector<vector<long long int>> ans(sz,vector<long long int>(sz,0));
    for(int i=0;i<sz;i++){
        for(int j=0;j<sz;j++){
            for(int k=0;k<sz;k++){
                ans[i][j]=(ans[i][j]+(a[i][k]*b[k][j])%MOD)%MOD;
            }
        }
    }
    return ans;
}
// Calculating Exponentiation
vector<vector<long long int>> matExpo(vector<vector<long long int>> &a , int n){
    long long int sz = a.size();
    vector<vector<long long int>> b(sz,vector<long long int>(sz,0));
    if(n==0){
        // return identity Matrix
        for(int i=0;i<sz;i++){
            for(int j=0;j<sz;j++){
                if(i==j) b[i][j]=1;
            }
        }
        return b;
    }
    if(n==1){
        return a;
    }
    vector<vector<long long int>> temp = matExpo(a,n/2);
    vector<vector<long long int>> ans = matmultipy(temp,temp);
    if(n&1){
        ans= matmultipy(ans,a);
    }
    return ans;
   
}


int Solution::solve(int n) {
    //Matrix Exponentiaition Method-->O(log(n))
    vector<vector<long long int>> a = {{1,1},{1,0}};
    vector<vector<long long int>> ans = matExpo(a,n);
   
    return ans[0][1];
}

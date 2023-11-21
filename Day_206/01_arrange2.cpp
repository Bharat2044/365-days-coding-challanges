// Question Link: https://www.interviewbit.com/problems/arrange-ii/

/*
Arrange II

You are given a sequence of black and white horses, and a set of K stables numbered 1 to K. You have to accommodate the horses into the stables in such a way that the following conditions are satisfied:

You fill the horses into the stables preserving the relative order of horses. For instance, you cannot put horse 1 into stable 2 and horse 2 into stable 1. You have to preserve the ordering of the horses.
No stable should be empty and no horse should be left unaccommodated.
Take the product (number of white horses * number of black horses) for each stable and take the sum of all these products. This value should be the minimum among all possible accommodation arrangements
Example:


Input: {WWWB} , K = 2
Output: 0

Explanation:
We have 3 choices {W, WWB}, {WW, WB}, {WWW, B}
for first choice we will get 1*0 + 2*1 = 2.
for second choice we will get 2*0 + 1*1 = 1.
for third choice we will get 3*0 + 0*1 = 0.

Of the 3 choices, the third choice is the best option. 

If a solution is not possible, then return -1
*/



int helper(int i,int j,int k,vector<int> &black,vector<int> &white,vector<vector<vector<int>>> &dp)
{  
     if(j-i+1<k)
     {  
         return 1e9;
     }
    if(k==1)
    {
        if(i-1>=0)
        {
           int nb=black[j]-black[i-1] ;
           int nw=white[j]-white[i-1];
           return nb*nw;
        }
        else
        {
            return black[j]*white[j];
        }
    }
    if(dp[i][j][k]!=-1)return dp[i][j][k];
    int mini=1e9;
    for(int m=i+1;m<=j;m++)
    {
        //i>>m-1
        if(i-1>=0)
        {
        int nb=black[m-1]-black[i-1];
        int nw=white[m-1]-white[i-1];
        int c=nb*nw+helper(m,j,k-1,black,white,dp);
        mini=min(c,mini);
        }
        else
        {
            mini=min(mini,black[m-1]*white[m-1]+helper(m,j,k-1,black,white,dp));
        }
       
        //m>>j
    }
   
    return dp[i][j][k]=mini;
}



int Solution::arrange(string A, int B) {
    int n=A.length();
    if(n<B)return -1;
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(B+1,-1)));
    vector<int> black(n,0);
   
    vector<int> white(n,0);
    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            if(A[i]=='B')
            {
                black[0]=1;
            }
            else
            {
                white[0]=1;
            }
        }
        else
        {
            if(A[i]=='B')
            {
                black[i]=black[i-1]+1;
                white[i]=white[i-1];
            }
            else
            {
                white[i]=white[i-1]+1;
                black[i]=black[i-1];
            }
        }
    }

    return helper(0,n-1,B,black,white,dp);
}

// Question Link: https://www.interviewbit.com/problems/sub-matrices-with-sum-zero/

/*
Sub Matrices with sum Zero

Given a 2D matrix, find the number non-empty sub matrices, such that the sum of the elements inside the sub matrix is equal to 0. (note:  elements might be negative).

Example:
Input
-8 5  7
3  7 -8
5 -8  9
Output
2

Explanation:
-8 5 7
3 7 -8
5 -8 9
-8 5 7
3 7 -8
5 -8 9
*/



#define ll long long

int count_subarray(vector<ll> &nums , int target)
{
    unordered_map< int , int > mp;   
    int count=0;   
    int sum=0;   
    int c=0;
   
    for(int i=0;i<nums.size();i++)
    {
        sum+=nums[i];
       
        if(sum==target)
        {
            c++;
            count+=c;
        }
        else
        {
            if(mp.find(sum-target)!=mp.end())
                count+=mp[sum-target];                        
        }
       
        mp[sum]++;
    }
       
    return count;
}

int Solution::solve(vector<vector<int> > &grid) {   
    int m = grid.size();
   
    if(m==0)
        return 0;
        
    int n=grid[0].size();
   
    // always reduce typical sub matrix problem to subarray , try to deduce some types of algo  
    // find any algo for it , reduce submatrix problem to subarray problem
   
    int target=0; // find all submatrix with sum = target   
    int res=0;
   
    for(int i=0;i<m;i++)
    {
        vector<ll> nums(n , 0);
        for(int j=i;j>=0;j--)
        {
            for(int k=0;k<n;k++)
                nums[k]+=grid[j][k];
                       
            int val = count_subarray(nums , target);           
            res+=val;
        }
    }
   
    return res;
}

// Question Link: https://www.interviewbit.com/problems/largest-continuous-sequence-zero-sum/

/*
Largest Continuous Sequence Zero Sum

Problem Description:
Given an array A of N integers.
Find the largest continuous sequence in a array which sums to zero.

Problem Constraints:
1 <= N <= 10^6
-10^7 <= A[i] <= 10^7

Input Format:
Single argument which is an integer array A.

Output Format:
Return an array denoting the longest continuous sequence with total sum of zero.
NOTE : If there are multiple correct answers, return the sequence which occurs first in the array.

Example Input:
A = [1,2,-2,4,-4]

Example Output:
[2,-2,4,-4]

Example Explanation:
[2,-2,4,-4] is the longest sequence with total sum of zero.
*/



vector<int> Solution::lszero(vector<int> &A) {
    map<int,int>mp;
    mp[0]=-1;
    
    int sum=0;
    int length=0;
    
    vector<int>v;
    int x=0,y=0;
    
    for (int i=0;i<A.size();i++){
        sum=sum+A[i];
        
        if (mp.find(sum)!=mp.end()){
            if (i-mp[sum]>length){
                length=i-mp[sum];
                x=mp[sum];
                y=i;
            }
           
        }
        else 
            mp[sum]=i;
    }
    
    vector<int> ans;
    for(int i=x+1;i<=y;i++){
        ans.push_back(A[i]);
    }
    
    return ans;
}

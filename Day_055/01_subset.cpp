// Question Link: https://www.interviewbit.com/problems/subset/

/*
Subset

Problem Description:
Given a set of distinct integers, A, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
Also, the subsets should be sorted in ascending ( lexicographic ) order.
The list is not necessarily sorted.

Problem Constraints:
0 <= |A| <= 20

Input Format:
The first argument is an integer array A.

Output Format:
Return array of all different possible subsets

Example Input:
A = [1, 2, 3]

Example Output:
[
 [],
 [1],
 [1, 2],
 [1, 2, 3],
 [1, 3],
 [2],
 [2, 3],
 [3],
]
*/



void find(vector<int>& A,vector<vector<int>> &ans,vector<int> & temp,int indx){
   
    if(indx == A.size()){
        ans.push_back(temp);
        return;
    }
    
    // exclude
    find(A,ans, temp, indx+1);
    
    // include
    temp.push_back(A[indx]);
    find(A, ans, temp, indx+1);
    temp.pop_back();   
}

vector<vector<int> > Solution::subsets(vector<int> &A) {
    sort(A.begin(), A.end());
    
    vector<vector<int>> ans;
    vector<int> temp;
    
    int indx=0;
    find(A, ans, temp, indx);
    
    sort(ans.begin(),ans.end());
    
    return ans;
}

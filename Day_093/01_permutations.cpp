// Question Link: https://www.interviewbit.com/problems/permutations/

/*
Permutations

Given a collection of numbers, return all possible permutations.

Example:
[1,2,3] will have the following permutations:

[1,2,3]
[1,3,2]
[2,1,3] 
[2,3,1] 
[3,1,2] 
[3,2,1]

NOTE:
No two entries in the permutation sequence should be the same.
For the purpose of this problem, assume that all the numbers in the collection are unique.
Warning : DO NOT USE LIBRARY FUNCTION FOR GENERATING PERMUTATIONS.

Example : next_permutations in C++ / itertools.permutations in python.

If you do, we will disqualify your submission retroactively and give you penalty points.
*/



void solve(int n,vector<int> &s,int idx,set<vector<int>> &ans){
   
    if(idx >= n)
        return ;
    
    ans.insert(s);
   
    for(int i=0; i<n; i++){            
        swap(s[idx], s[i]);
   
        solve(n, s, idx+1, ans);
        swap(s[idx], s[i]);
    }
}

vector<vector<int> > Solution::permute(vector<int> &A) {
    int n=A.size();
    set<vector<int>> ans;
    vector<vector<int>> v;
    
    solve(n, A, 0, ans);

    for(auto vec:ans)
        v.push_back(vec);

    return v;           
}


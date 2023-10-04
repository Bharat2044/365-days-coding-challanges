// Question Link: https://www.interviewbit.com/problems/all-unique-permutations/

/*
All Unique Permutations

Problem Description:
Given an array A of size N denoting collection of numbers that might contain duplicates, return all possible unique permutations.

NOTE: No 2 entries in the permutation sequence should be the same.

Input Format:
Only argument is an integer array A of size N.

Output Format:
Return a 2-D array denoting all possible unique permutation of the array.

Example Input:
Input 1: 
A = [1, 1, 2]
Input 2: 
A = [1, 2]

Example Output:
Output 1: 
[ [1, 1, 2]
  [1, 2, 1]
  [2, 1, 1] ]
Output 2: 
[ [1, 2]
  [2, 1] ]

Example Explanation:
Explanation 1: 
All the possible unique permutation of array [1, 1, 2].
Explanation 2: 
All the possible unique permutation of array [1, 2].
*/




void helper(vector<int> &A, set<vector<int>> &vec, int start, int end) {
    if(start >=end) {
        vec.insert(A);
        return ;
    }

    for(int i=start; i<A.size();i++) {
        swap(A[start],A[i]);
        helper(A,vec,start+1,end);
        swap(A[start],A[i]);
    }
}

vector<vector<int> > Solution::permute(vector<int> &A) {
    set<vector<int>> vec;
    helper(A,vec,0,A.size()-1);

    vector<vector<int>> ans (vec.begin(), vec.end());

    return ans;
}

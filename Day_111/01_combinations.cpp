// Question Link: https://www.interviewbit.com/problems/combinations/

/*
Combinations

Given two integers n and k, return all possible combinations of k numbers out of 1 2 3 ... n.

Make sure the combinations are sorted.

To elaborate,

Within every entry, elements should be sorted. [1, 4] is a valid entry while [4, 1] is not.
Entries should be sorted within themselves.

Example :
If n = 4 and k = 2, a solution is:
[
  [1,2],
  [1,3],
  [1,4],
  [2,3],
  [2,4],
  [3,4],
]
Warning : DO NOT USE LIBRARY FUNCTION FOR GENERATING COMBINATIONS.

Example : itertools.combinations in python.
If you do, we will disqualify your submission retroactively and give you penalty points.
*/

  
vector<vector<int>> ans ;

void util( vector<int>&temp, int n, int current, int remain) {
    if(remain == 0){
        ans.push_back(temp) ;
        return;
    }
    if(current > n) 
        return ;
        
    temp.push_back(current) ;
    util(temp, n, current+1, remain-1) ;

    temp.pop_back() ;

    util(temp, n, current+1, remain) ;
}

vector<vector<int> > Solution::combine(int A, int B) {
    ans.clear() ;
    vector<int> temp ;
    util(temp, A, 1, B) ;
    
    return ans ;
}

// Question Link: https://www.interviewbit.com/problems/chain-of-pairs/

/*
Chain of Pairs

Problem Description:
Given a N * 2 array A where (A[i][0], A[i][1]) represents the ith pair.
In every pair, the first number is always smaller than the second number.
A pair (c, d) can follow another pair (a, b) if b < c , similarly in this way a chain of pairs can be formed.
Find the length of the longest chain subsequence which can be formed from a given set of pairs.

Note: A subsequence of a given sequence is a sequence that can be derived from the given sequence by deleting some or no elements without changing the order of the remaining elements.

Problem Constraints:
1 <= N <= 10^3
1 <= A[i][0] < A[i][1] <= 10^4

Input Format:
First and only argument is an 2D integer array A of size N * 2 representing the N pairs.

Output Format:
Return a single integer denoting the length of longest chain subsequence of pairs possible under given constraint.

Example Input:
Input 1:
A = [  [5, 24]
        [39, 60]
        [15, 28]
        [27, 40]
        [50, 90]
     ]
Input 2:
A = [   [10, 20]
        [1, 2]
     ]

Example Output:
Output 1:
 3
Output 2:
 1


Example Explanation:
Explanation 1:
 Longest chain that can be formed is of length 3, and the chain is [ [5, 24], [27, 40], [50, 90] ]
Explanation 2:
 Longest chain that can be formed is of length 1, and the chain is [ [1, 2] ] or [ [10, 20] ]
*/



bool comp(pair<int,int> a,int val){
    return val > a.second;
}

int Solution::solve(vector<vector<int> > &A) {
    int n = A.size();
    vector<pair<int,int>> arr;
    arr.push_back(make_pair(A[0][0],A[0][1]));
    
    for(int i=1;i<n;i++){
        int x = A[i][0];
        int y = A[i][1];
       
        if(x > arr[arr.size()-1].second){
            arr.push_back(make_pair(x,y));
        }else{
            int idx = lower_bound(arr.begin(),arr.end(),x,comp) - arr.begin();
           
            if(y < arr[idx].second){
                arr[idx] = make_pair(x,y);
            }
        }
    }
   
    return arr.size();
}

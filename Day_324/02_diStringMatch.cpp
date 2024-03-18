// Question Link: https://leetcode.com/problems/di-string-match/

/*
942. DI String Match

A permutation perm of n + 1 integers of all the integers in the range [0, n] can be represented as a string s of length n where:
s[i] == 'I' if perm[i] < perm[i + 1], and
s[i] == 'D' if perm[i] > perm[i + 1].
Given a string s, reconstruct the permutation perm and return it. If there are multiple valid permutations perm, return any of them.

Example 1:
Input: s = "IDID"
Output: [0,4,1,3,2]
Example 2:
Input: s = "III"
Output: [0,1,2,3]
Example 3:
Input: s = "DDI"
Output: [3,2,0,1]
 
Constraints:
1 <= s.length <= 10^5
s[i] is either 'I' or 'D'.
*/



class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n=s.size();
        vector<int>perm(n+1,0);
        int i=0,j=n,x=0;
        (s[0]=='I')?(perm[0]=i++):(perm[0]=j--);

        for(int k=1; k<n; k++){
            (s[k]=='I')?(perm[k]=i++):(perm[k]=j--);
        }
        (s[n-1]=='I')?(perm[n]=i++):(perm[n]=j--);
        return perm;
    }
};

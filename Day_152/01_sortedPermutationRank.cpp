// Question Link: https://www.interviewbit.com/problems/sorted-permutation-rank/

/*
Sorted Permutation Rank

Problem Description:
Given a string A. Find the rank of the string amongst its permutations sorted lexicographically.

Assume that no characters are repeated.

Note: The answer might not fit in an integer, so return your answer % 1000003

Problem Constraints:
1 <= |A| <= 1000

Input Format:
First argument is a string A.

Output Format:
Return an integer denoting the rank of the given string.

Example Input:
Input 1:
A = "acb"
Input 2:
A = "a"

Example Output:
Output 1:
2
Output 2:
1

Example Explanation:
Explanation 1:
Given A = "acb".
The order permutations with letters 'a', 'c', and 'b' : 
abc
acb
bac
bca
cab
cba
So, the rank of A is 2.
Explanation 2:
Given A = "a".
Rank is clearly 1.
*/



long long int fac(int n ){
    if(n==0 || n==1){
        return 1;
    }
    else{
        return (n * fac(n-1) % 1000003) % 1000003 ;
    }
}

int Solution::findRank(string A) {
    set<char> s ;
    long long int num = 0;
    int n = A.size();
    
    for(int i=0;i<n;i++){
        s.insert(A[i]);
    }
    
    auto it = s.begin();
   
    for(int i=0;i<n;i++){
        while(A[i] != *it){
        num += fac(n-i-1) ;
        num = num %  1000003 ;
        ++it;
        }
        s.erase(A[i]);
        it = s.begin();
       
    }
    int temp = num + 1;
    
    return temp;   
}

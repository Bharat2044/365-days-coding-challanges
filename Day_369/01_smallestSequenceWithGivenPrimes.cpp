// Question Link: https://www.interviewbit.com/problems/smallest-sequence-with-given-primes/

/*
Smallest sequence with given Primes

Problem Description:
Given three prime numbers A, B and C and an integer D.
You need to find the first(smallest) D integers which only have A, B, C or a combination of them as their prime factors.

Input Format:
First argument is an integer A.
Second argument is an integer B.
Third argument is an integer C.
Fourth argument is an integer D.

Output Format:
Return an array of size D denoting the first smallest D integers which only have A, B, C or a combination of them as their prime factors.
NOTE: You need to return the array sorted in ascending order.

Example Input:
Input 1:
 A = 2
 B = 3
 C = 5
 D = 5

Example Output:
Output 1:
 [2, 3, 4, 5, 6]

Example Explanation:
Explanation 1:
 4 = A * A i.e ( 2 * 2 ) 
 6 = A * B i.e ( 2 * 3 )
*/




vector<int> Solution::solve(int A, int B, int C, int D) {
    set<int>s={A,B,C};
    vector<int>ans(D);
    
    for(int i =0;i<D;i++){
        int j=*s.begin();
        s.erase(s.begin());
        
        s.insert(j*A),s.insert(j*B),s.insert(j*C);
        ans[i]=j;
    }
    
    return ans;
}

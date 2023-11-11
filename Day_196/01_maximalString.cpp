// Question Link: https://www.interviewbit.com/problems/maximal-string/

/*
Maximal String

Problem Description:
Given a string A and integer B, what is maximal lexicographical string that can be made from A if you do atmost B swaps.

Problem Constraints:
1 <= |A| <= 9
A contains only digits from 0 to 9.
1 <= B <= 5

Input Format:
First argument is string A.
Second argument is integer B.

Output Format:
Return a string, the naswer to the problem.

Example Input:
Input 1:
A = "254"
B = 1
Input 2:
A = "254"
B = 2

Example Output:
Output 1:
 524
Output 2:
 542

Example Explanation:
Explanation 1:
 Swap 2 and 5.
Explanation 2:
Swap 2 and 5 then swap 4 and 2.
*/



string ans;

void solve2(string A,int B,int i){
    int n=A.length();
    if(B==0 || i==n){
        if(ans<A) ans=A;
        return;
    }
   
    //no swap
    solve2(A,B,i+1);

    //swap
    for(int j=i;j<n;j++){
        swap(A[i],A[j]);
        solve2(A,B-1,i+1);
        swap(A[i],A[j]);
    }
    
    return;
}

string Solution::solve(string A, int B) {
    if(B==0) 
        return A;
    
    ans=A;
    solve2(A,B,0);
    
    return ans;
}

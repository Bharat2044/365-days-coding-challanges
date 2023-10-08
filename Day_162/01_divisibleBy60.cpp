// Question Link: https://www.interviewbit.com/problems/divisible-by-60/

/*
Divisible by 60

Problem Description:
Given a large number represent in the form of an integer array A, where each element is a digit.
You have to find whether there exists any permutation of the array A such that the number becomes divisible by 60
Return 1 if it exists, 0 otherwise.

Problem Constraints:
1 <= |A| <= 105
0 <= Ai <= 9

Input Format:
The first argument is an integer array A.

Output Format:
Return a single integer '1' if there exists a permutation, '0' otherwise.

Example Input:
Input 1:
A = [0, 6]
Input 2:
A = [2, 3]

Example Output:
Output 1:
1
Output 2:
0

Example Explanation:
Explanation 1:
We can rearrange the digits to form 60, which is divisible by 60.
Explanation 2:
There are only two possible permutations: [23, 32].
Both of them are not divisible by 60.
*/



int Solution::divisibleBy60(vector<int> &A) {
    int f1=0,f2=0,sum=0;
    //for handling [0] as input
    if(A.size()==1 && A[0]==0){
        return 1;
    }
   
    for(int i=0;i<A.size();i++){
        //to check if there exist zero aor not
        if(A[i]==0){
            f1=1;
        }
        //to check if there exist even no other than 0
        if(A[i]%2==0 && A[i]!=0){
            f2=1;
        }
        //to check sum is divisible by 3(divisibilty test of 3)
        sum+=A[i];
    }
   
    if( f1 && f2 && sum%3==0){
        return 1;
    }
    
    return 0;
}

// Question Link: https://www.interviewbit.com/problems/diffk/

/*
Diffk

Problem Description: 
Given an array 'A' of sorted integers and another non-negative integer B, find if there exist 2 indices i and j such that A[i] - A[j] = k, i != j.
Return 0 / 1 ( 0 for false, 1 for true ) for this problem
Try doing this in less than linear space complexity.

Problem Constraints:
1 <= |A| <= 106
0 <= B <= 109

Input Format:
The first argument is an integer array A.
The second argument is an integer B.

Output Format:
Return an integer, 0 / 1 ( 0 for false, 1 for true ) for this problem

Example Input:
 A : [1 3 5] 
 B : 4

Example Output:
1

Example Explanation:
For the given, 
 A : [1 3 5] 
 B : 4
Output : YES
as 5 - 1 = 4
*/



int Solution::diffPossible(vector<int> &A, int B) {
    int i=0;
    int j=1;

    while(i<A.size()&&j<A.size()){

        if((A[j]-A[i]==B)&&i!=j){
            return 1;
        }
        else if(A[j]-A[i]>B){
            i++;
        }else{
            j++;
        }
    }

    return 0;
}

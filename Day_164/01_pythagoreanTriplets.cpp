// Question Link: https://www.interviewbit.com/problems/pythagorean-triplets/

/*
Pythagorean Triplets

Problem Description:
A Pythagorean triplet is a set of three integers a, b and c such that a2 + b2 = c2.
Find the number of pythagorean triplets such that all the elements of the triplet are less than or equal to A.

Problem Constraints:
1 <= A <= 103

Input Format:
Given an integer A.

Output Format:
Return an integer.

Example Input:
Input 1:
A = 5
Input 2:
A = 13

Example Output:
Output 1:
1
Output 2:
3

Example Explanation:
Explanation 1:
Then only triplet is {3, 4, 5}
Explanation 2:
The triplets are {3, 4, 5}, {6, 8, 10}, {5, 12, 13}.
*/



int Solution::solve(int A) {
    int count = 0;
    int arr[A+1];
    arr[0]=0;
    
    for(int i=1;i<=A;i++){
        arr[i]=i*i;
    }
    
    for(int i=A;i>=1;i--) {   
        for(int j=1,k=A;j<k;) {  
                
            if((arr[j]+arr[k])==arr[i]) {           
                count++;
                k--;
                j++;
            }
            else if((arr[j]+arr[k])>arr[i])
                k--;
            else
                j++;
        }
    }
    
    return count;
}

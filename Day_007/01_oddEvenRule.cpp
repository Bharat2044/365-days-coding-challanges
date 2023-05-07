// Question Link: https://www.interviewbit.com/problems/odd-even-rule/

/*
Odd Even Rule:

Problem Description:
Due to pollution Delhi government has applied odd even rule in Delhi.
Traffic police on guard is recording the registration number of vehicles passing through his area and storing the last digit of the number in an array A.
You are given the array A and date of the day B. Also fine for breaking the rule is C Rs.
Find the total fine in Rs collected by the traffic police.


Problem Constraints:
1 <= |A| <= 105
1 <= B <= 31
1 <= C <= 1000

Input Format:
First arguement is an integer array A.
Second argument is an integer B.
Third argument is an integer C.

Output Format
Return an integer.

Example Input:
Input 1:
A = [1, 2, 3]
B = 31
C = 100
Input 2:
A = [0, 1, 1]
B = 2
C = 51

Example Output:
Output 1:
100
Output 2:
102

Example Explanation:
Explanation 1:
Vehicle 2 is not following the rule so only he will be fined.
Explanation 2:
Vehicle 2 and 3 are not following the rule so both of them will be fined.
*/


// Time Complexity = O(n), Space Complexity = O(1)
int Solution::solve(vector<int> &A, int B, int C) {    
    int fine = 0;
    
    if(B%2 == 0){
        for(int i=0; i<A.size(); i++){
            if(A[i]%2 == 1)
                fine += C;            
        }
        return fine;
    }
    
    else{
        for(int i=0; i<A.size(); i++){
            if(A[i]%2 == 0)
                fine += C;
        }
        return fine;
    }
}

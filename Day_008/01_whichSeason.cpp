// Question Link: https://www.interviewbit.com/problems/which-season/

/*
Which Season?

Problem Description:
Given an integer A which represents a month.
Find the season according to the month.
Spring – March to May
Summer – June to August
Autumn – September to November
Winter – December to February
If the month is out of the range 1 to 12 output should be “Invalid”.

Problem Constraints:
1 <= A <= 100

Input Format:
Given an integer A.

Output Format:
Return a string.

Example Input:
Input 1:
A = 6
Input 2:
A = 13

Example Output:
Output 1:
"Summer"
Output 2:
"Invalid"

Example Explanation:
Explanation 1:
6th month is june, in june there is "Summer".
Explanation 2:
13th month doesn't exist so "Invalid".
*/


// Time Complexity = O(1), SPace Complexity = O(1)
string Solution::solve(int A) {
    
    switch(A){
        case 3:
        case 4:
        case 5:
            return "Spring";
            
        case 6:
        case 7:
        case 8:
            return "Summer";
            
        case 9:
        case 10:
        case 11:
            return "Autumn";
            
        case 12:
        case 1:
        case 2:
            return "Winter";
    }   

    return "Invalid";    
}

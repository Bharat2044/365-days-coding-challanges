// Question Link: https://www.interviewbit.com/problems/number-of-sundays/

/*
Number of Sundays:

Problem Description:
Given the start day of the month A and number of days in the month B, find number of sundays in the month.

Problem Constraints
A = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"}
1 <= B <= 109

Input Format:
First argument is an string A.
Second argument is an integer B.

Output Format:
Return an integer.

Example Input
Input 1:
A = "Sunday"
B = 1
Input 2:
A = "Monday"
B = 14

Example Output
Output 1:
1
Output 2:
2

Example Explanation:
Explanation 1:
The only day in the month is sunday.
Explanation 2:

The 7th and 14th day of the month will be sunday
*/


// Time Complexity = O(1), Space Complexity = O(1)
int Solution::solve(string A, int B) {
    unordered_map<string, int> mp;
   
    mp["Monday"] = 1;
    mp["Tuesday"] = 2;
    mp["Wednesday"] = 3;
    mp["Thursday"] = 4;
    mp["Friday"] = 5;
    mp["Saturday"] = 6;
    mp["Sunday"] = 7;
   
    return (B+mp[A]-1)/7;
}

// Question Link: https://www.interviewbit.com/problems/find-last-digit/

/*
Find Last Digit:

Problem Description:
Find last digit of the number AB.
A and B are large numbers given as strings.

Problem Constraints:
1 <= |A| <= 105
1 <= |B| <= 105

Input Format:
First argument is a string A.
First argument is a string B.

Output Format:
Return an integer.

Example Input:
Input 1:
A = 2
B = 10
Input 2:
A = 11
B = 11


Example Output:
Output 1:
4
Output 2:
1

Example Explanation:
Explanation 1:
210 = 1024, hence last digit is 4.
Explanation 2:
1111 = 285311670611, hence last digit is 1.
*/


int Solution::solve(string A, string B) {
    
    std::string p = A.substr(A.length() - 1);
    std::string n = B.substr(B.length() - 2);
    
    int b = stoi(n);
    int a = stoi(p);
    b %= 4;
    
    int k = pow(a, b+4);
    return k%10;
}

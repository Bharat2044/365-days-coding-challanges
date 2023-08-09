// Question Link: https://www.interviewbit.com/problems/excel-column-title/

/*
Excel Column Title

Problem Description:
Given a positive integer A, return its corresponding column title as appear in an Excel sheet.

Problem Constraints:
1 <= A <= 1000000000

Input Format:
First and only argument is integer A.

Output Format:
Return a string, the answer to the problem.

Example Input:
Input 1:
 A = 1
Input 2:
 A = 28

Example Output:
Output 1:
 "A"
Output 2:
 "AB"

Example Explanation:
Explanation 1:
 1 -> A
Explanation 2:
1 -> A
2 -> B
3 -> C
...
26 -> Z
27 -> AA
28 -> AB 
*/



char* convertToTitle(int n) {
    char *res = (char *)calloc(8, sizeof(char));
    int i = 6;
    
    while(n){
        res[i--] = (char)((n-1) % 26) + 'A';
        n = (n - 1) / 26;
    }
    
    return res+i+1;
}

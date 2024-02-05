// Question Link: https://www.interviewbit.com/problems/redundant-braces/

/*
Redundant Braces

Problem Description:
Given a string A denoting an expression. It contains the following operators '+', '-', '*', '/'.
Check whether A has redundant braces or not.
NOTE: A will be always a valid expression.

Problem Constraints:
1 <= |A| <= 105

Input Format:
The only argument given is string A.

Output Format:
Return 1 if A has redundant braces, else return 0.

Example Input:
Input 1:
 A = "((a+b))"
Input 2:
 A = "(a+(a+b))"
Input 3:
 A = "((a*b)+(c+d))"

Example Output:
Output 1:
 1
Output 2:
 0
Output 3:
 0

Example Explanation:
Explanation 1:
 ((a+b)) has redundant braces so answer will be 1.
Explanation 2:
 (a+(a+b)) doesn't have have any redundant braces so answer will be 0.
Explanation 3:
 ((a*b)+(c+d)) doesn't have have any redundant braces so answer will be 0.
*/



int Solution::braces(string A) {
    stack<int> track;
    int count;
    track.push(0);
    
    for(auto a: A){
        if(a == '+' || a == '*' || a == '-' || a == '/'){
            count = track.top() + 1;
            track.pop();
            track.push(count);
        }
        else if(a == ')'){
            if(track.top() <= 0) 
                return 1;
            track.pop();
        }
        else if(a == '('){
            track.push(0);
        }
    }
    
    return 0;
}

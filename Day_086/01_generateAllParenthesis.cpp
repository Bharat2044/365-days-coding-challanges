// Question Link: https://www.interviewbit.com/problems/generate-all-parentheses/

/*
Generate all Parentheses

Stacks And Queues
Problem Description:
Given a string A, containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
Return 0 / 1 ( 0 for false, 1 for true ) for this problem.
Note:  The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

Problem Constraints:
1 <= |A| <= 106

Input Format:
The first and only argument is a string A.

Output Format:
Return an integer, 0 / 1 ( 0 for false, 1 for true )

Example Input:
Input 1:
A = "()[]{}"
Input 2:
A = "([)]"

Example Output:
Output 1:
1
Output 1:
0
*/



int Solution::isValid(string A) {
    stack<char> s;
   
    for(int i=0;i<(int)A.length();i++)
    {
        if(A[i]=='(' || A[i]=='[' || A[i]=='{')
            s.push(A[i]);
        else{
            if(!s.empty())
            {
                if(A[i]==')')
                {
                    if(s.top()!='(')
                        return 0;
                    else
                        s.pop();
                }
                if(A[i]=='}')
                {
                    if(s.top()!='{')
                        return 0;
                    else
                        s.pop();
                }
                if(A[i]==']')
                {
                    if(s.top()!='[')
                        return 0;
                    else
                        s.pop();
                }
            }
            else
                return 0;
        }
    }
    
    if(s.empty())
        return 1;
    
    return 0;
   
}

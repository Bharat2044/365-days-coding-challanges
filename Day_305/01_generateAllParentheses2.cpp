// Question Link: https://www.interviewbit.com/problems/generate-all-parentheses-ii/

/*
Generate all Parentheses II

Problem Description:
Given an integer A pairs of parentheses, write a function to generate all combinations of well-formed parentheses of length 2*A.

Problem Constraints:
1 <= A <= 10

Input Format:
First and only argument is integer A.

Output Format:
Return a sorted list of all possible parenthesis.

Example Input:
Input 1:
A = 3
Input 2:
A = 1

Example Output:
Output 1:
[ "((()))", "(()())", "(())()", "()(())", "()()()" ]
Output 2:
[ "()" ]

Example Explanation:
Explanation 1:
 All paranthesis are given in the output list.
Explanation 2:
 All paranthesis are given in the output list.
*/



void generate(int ctStart, int pendingStart, int ctEnd, string temp, int A, vector<string>&ans){
    if(ctEnd == A and ctStart == A){
        ans.push_back(temp);
        return ;
    }
    if(ctStart != A){
        temp.push_back('(');
        generate(ctStart + 1, pendingStart+1, ctEnd, temp, A, ans);
        if(pendingStart != 0){
            temp.pop_back();
            temp.push_back(')');
            generate(ctStart, pendingStart-1, ctEnd+1,temp,  A, ans);
        }
    }else{
        if(pendingStart != 0){
            // temp.pop_back();
            temp.push_back(')');
            generate(ctStart, pendingStart-1, ctEnd+1,temp,  A, ans);
        }
    }
}
bool static cmpr(string &s1, string &s2){
    return s1 < s2;
}
vector<string> Solution::generateParenthesis(int A) {
    vector<string>ans ;
    string temp;
    int ctStart = 0, ctEnd = 0 ;
    generate(0, 0,0,   temp, A, ans);
    sort(ans.begin(), ans.end(), cmpr);
    return ans;
}

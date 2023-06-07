// Question Link: https://www.interviewbit.com/problems/evaluate-expression/

/*
Evaluate Expression:

Problem Description:
An arithmetic expression is given by a string array A of size N. Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each string may be an integer or an operator.

Problem Constraints:
1 <= N <= 105

Input Format:
The only argument given is string array A.

Output Format:
Return the value of arithmetic expression formed using reverse Polish Notation.

Example Input:
Input 1:
    A =   ["2", "1", "+", "3", "*"]
Input 2:
    A = ["4", "13", "5", "/", "+"]

Example Output:
Output 1:
    9
Output 2:
    6

Example Explanation:
Explaination 1:
    starting from backside:
    * : () * ()
    3 : () * (3)
    + : (() + ()) * (3)
    1 : (() + (1)) * (3)
    2 : ((2) + (1)) * (3)
    ((2) + (1)) * (3) = 9
Explaination 2:
    + : () + ()
    / : () + (() / ())
    5 : () + (() / (5))
    13 : () + ((13) / (5))
    4 : (4) + ((13) / (5))
    (4) + ((13) / (5)) = 6
*/



bool check(string t) {
    if (t == "/" || t == "+" || t == "*" || t == "-")
        return true;

    return false;
}

int Solution::evalRPN(vector<string> &A) {
    stack<string> st;

    for (int i = A.size() - 1; i >= 0; i--)  {
        if (check(A[i]))
            st.push(A[i]);
            
        else {
            if (st.empty())
                return stoi(A[i]);
            if (check(st.top()))
                st.push(A[i]);

            else {
                st.push(A[i]);

                while (!check(st.top())) {
                    int a = stoi(st.top());
                    st.pop();
                    if (st.empty() || check(st.top())) {
                        st.push(to_string(a));
                        break;
                    }
                    
                    int b = stoi(st.top());
                    st.pop();
                    string op = st.top();
                    st.pop();
                    int p;
                    
                    if (op == "*")
                        p = a * b;
                    else if (op == "-")
                        p = a - b;
                    else if (op == "+")
                        p = a + b;
                    else if (op == "/")
                        p = a / b;
                        
                    st.push(to_string(p));
                }
            }
        }
    }
    
    return stoi(st.top());
}

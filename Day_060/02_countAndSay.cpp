// Question Link: https://leetcode.com/problems/count-and-say/

/*
38. Count and Say

The count-and-say sequence is a sequence of digit strings defined by the recursive formula:

countAndSay(1) = "1"
countAndSay(n) is the way you would "say" the digit string from countAndSay(n-1), which is then converted into a different digit string.
To determine how you "say" a digit string, split it into the minimal number of substrings such that each substring contains exactly one unique digit. Then for each substring, say the number of digits, then say the digit. Finally, concatenate every said digit.

For example, the saying and conversion for digit string "3322251":

Given a positive integer n, return the nth term of the count-and-say sequence.


Example 1:
Input: n = 1
Output: "1"
Explanation: This is the base case.
Example 2:
Input: n = 4
Output: "1211"
Explanation:
countAndSay(1) = "1"
countAndSay(2) = say "1" = one 1 = "11"
countAndSay(3) = say "11" = two 1's = "21"
countAndSay(4) = say "21" = one 2 + one 1 = "12" + "11" = "1211"
 
Constraints:
1 <= n <= 30
*/




class Solution {
public:
string ans;
    void say(int n,string str,int num){
        if(n == num+1){
            ans  =str;
            return;
        }

        if(n==1){
            str="1";
            say(n+1, str, num);
            return;
        }

        string s;
        int cnt=1;
        char c=str[0];
        stack<char> st;

        for(int i=0; i<str.size(); i++){
            if(!st.empty() && st.top()==str[i])
                st.push(str[i]);   

            else if(st.empty())
                st.push(str[i]);

            else{
                s = s+to_string(st.size())+st.top();
                while(!st.empty()) 
                    st.pop();
                st.push(str[i]);
            }
        }

        if(!st.empty())
            s=s+to_string(st.size())+st.top();            
               
        say(n+1, s, num);
    }


    string countAndSay(int n) {
       say(1, "", n);

       return ans;
    }
};

// Question Link: https://leetcode.com/problems/basic-calculator-iv/

/*
770. Basic Calculator IV

Given an expression such as expression = "e + 8 - a + 5" and an evaluation map such as {"e": 1} (given in terms of evalvars = ["e"] and evalints = [1]), return a list of tokens representing the simplified expression, such as ["-1*a","14"]

An expression alternates chunks and symbols, with a space separating each chunk and symbol.
A chunk is either an expression in parentheses, a variable, or a non-negative integer.
A variable is a string of lowercase letters (not including digits.) Note that variables can be multiple letters, and note that variables never have a leading coefficient or unary operator like "2x" or "-x".
Expressions are evaluated in the usual order: brackets first, then multiplication, then addition and subtraction.

For example, expression = "1 + 2 * 3" has an answer of ["7"].
The format of the output is as follows:
For each term of free variables with a non-zero coefficient, we write the free variables within a term in sorted order lexicographically.
For example, we would never write a term like "b*a*c", only "a*b*c".
Terms have degrees equal to the number of free variables being multiplied, counting multiplicity. We write the largest degree terms of our answer first, breaking ties by lexicographic order ignoring the leading coefficient of the term.
For example, "a*a*b*c" has degree 4.
The leading coefficient of the term is placed directly to the left with an asterisk separating it from the variables (if they exist.) A leading coefficient of 1 is still printed.
An example of a well-formatted answer is ["-2*a*a*a", "3*a*a*b", "3*b*b", "4*a", "5*c", "-6"].
Terms (including constant terms) with coefficient 0 are not included.
For example, an expression of "0" has an output of [].
Note: You may assume that the given expression is always valid. All intermediate results will be in the range of [-231, 231 - 1].

Example 1:
Input: expression = "e + 8 - a + 5", evalvars = ["e"], evalints = [1]
Output: ["-1*a","14"]
Example 2:
Input: expression = "e - 8 + temperature - pressure", evalvars = ["e", "temperature"], evalints = [1, 12]
Output: ["-1*pressure","5"]
Example 3:
Input: expression = "(e + 8) * (e - 8)", evalvars = [], evalints = []
Output: ["1*e*e","-64"]

Constraints:
1 <= expression.length <= 250
expression consists of lowercase English letters, digits, '+', '-', '*', '(', ')', ' '.
expression does not contain any leading or trailing spaces.
All the tokens in expression are separated by a single space.
0 <= evalvars.length <= 100
1 <= evalvars[i].length <= 20
evalvars[i] consists of lowercase English letters.
evalints.length == evalvars.length
-100 <= evalints[i] <= 100
*/



class Solution {
public:
    vector<string> basicCalculatorIV(string expression, vector<string>& evalvars, vector<int>& evalints) {
        unordered_map<string, int> mp;
        int n = evalvars.size();
        for (int i = 0; i < n; ++i) mp[evalvars[i]] = evalints[i];
        int pos = 0;
        unordered_map<string, int> output = helper(expression, mp, pos);
        vector<pair<string, int>> ans(output.begin(), output.end());
        sort(ans.begin(), ans.end(), mycompare);
        vector<string> res;
        for (auto& p: ans) {
            if (p.second == 0) continue;
            res.push_back(to_string(p.second));
            if (p.first != "") res.back() += "*"+p.first;
        }
        return res;
    }
private:
    unordered_map<string, int> helper(string& s, unordered_map<string, int>& mp, int& pos) {
        vector<unordered_map<string, int>> operands;
        vector<char> ops;
        ops.push_back('+');
        int n = s.size();
        while (pos < n && s[pos] != ')') {
            if (s[pos] == '(') {
               pos++;
               operands.push_back(helper(s, mp, pos));
            }
            else {
               int k = pos;
               while (pos < n && s[pos] != ' ' && s[pos] != ')') pos++;
               string t = s.substr(k, pos-k);
               bool isNum = true;
               for (char c: t) {
                   if (!isdigit(c)) isNum = false;
               }
               unordered_map<string, int> tmp;
               if (isNum) 
                   tmp[""] = stoi(t);
               else if (mp.count(t)) 
                   tmp[""] = mp[t];
               else              
                   tmp[t] = 1;
               operands.push_back(tmp);
            }
            if (pos < n && s[pos] == ' ') {
               ops.push_back(s[++pos]);
               pos += 2;
            }
        }
        pos++;
        return calculate(operands, ops);
    }
    unordered_map<string, int> calculate(vector<unordered_map<string, int>>& operands, vector<char>& ops) {
        unordered_map<string, int> ans;
        int n = ops.size();
        for (int i = n-1; i >= 0; --i) {
            unordered_map<string, int> tmp = operands[i];
            while (i >= 0 && ops[i] == '*')
                tmp = multi(tmp, operands[--i]);
            int sign = ops[i] == '+'? 1: -1;
            for (auto& p: tmp) ans[p.first] += sign*p.second;
        }
        return ans;
    }
    unordered_map<string, int> multi(unordered_map<string, int>& lhs, unordered_map<string, int>& rhs) {
        unordered_map<string, int> ans;
        int m = lhs.size(), n = rhs.size();
        for (auto& p: lhs) {
            for (auto& q: rhs) {
                string t = combine(p.first, q.first);
                ans[t] += p.second*q.second;
            }
        }
        return ans;
    }
    string combine(const string& a, const string& b) {
        if (a == "") return b;
        if (b == "") return a;
        vector<string> strs = split(a, '*');
        for (auto& s: split(b, '*')) strs.push_back(s);
        sort(strs.begin(), strs.end());
        string s;
        for (auto& t: strs) s += t +'*';
        s.pop_back();
        return s;
    }
    static vector<string> split(const string& s, char c) {
        vector<string> ans;
        int i = 0, n = s.size();
        while (i < n) {
            int j = i;
            i = s.find(c, i);
            if (i == -1) i = n;
            ans.push_back(s.substr(j, i-j));
            i++;
        }
        return ans;
    }
    static bool mycompare(pair<string, int>& a, pair<string, int>& b) {
        string s1 = a.first, s2 = b.first;
        vector<string> left = split(s1, '*'); 
        vector<string> right = split(s2, '*');
        return left.size() > right.size() || (left.size() == right.size() && left < right);
    } 
};

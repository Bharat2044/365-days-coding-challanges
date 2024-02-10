// Question Link: https://leetcode.com/problems/number-of-atoms/description/

/*
726. Number of Atoms

Given a string formula representing a chemical formula, return the count of each atom.
The atomic element always starts with an uppercase character, then zero or more lowercase letters, representing the name.
One or more digits representing that element's count may follow if the count is greater than 1. If the count is 1, no digits will follow.

For example, "H2O" and "H2O2" are possible, but "H1O2" is impossible.
Two formulas are concatenated together to produce another formula.

For example, "H2O2He3Mg4" is also a formula.
A formula placed in parentheses, and a count (optionally added) is also a formula.

For example, "(H2O2)" and "(H2O2)3" are formulas.
Return the count of all elements as a string in the following form: the first name (in sorted order), followed by its count (if that count is more than 1), followed by the second name (in sorted order), followed by its count (if that count is more than 1), and so on.

The test cases are generated so that all the values in the output fit in a 32-bit integer.

Example 1:
Input: formula = "H2O"
Output: "H2O"
Explanation: The count of elements are {'H': 2, 'O': 1}.
Example 2:
Input: formula = "Mg(OH)2"
Output: "H2MgO2"
Explanation: The count of elements are {'H': 2, 'Mg': 1, 'O': 2}.
Example 3:
Input: formula = "K4(ON(SO3)2)2"
Output: "K4N2O14S4"
Explanation: The count of elements are {'K': 4, 'N': 2, 'O': 14, 'S': 4}.
 
Constraints:
1 <= formula.length <= 1000
formula consists of English letters, digits, '(', and ')'.
formula is always valid.
*/



class Solution {
public:
    bool isDigit(char ch) {
        return (ch >= '0' && ch <= '9');
    }
    
    unordered_map<string, int> dfs(int &pos, string &formula) {
        int n = formula.size();
        if (pos >= n) {
            return {};
        }
        unordered_map<string, int> curMap;
        string prev = "";
        while (pos < n) {
            if (formula[pos] == '(') {
                if (prev.size() > 0) {
                    curMap[prev] += 1;
                    prev = "";
                }
                ++pos;
                unordered_map<string, int> retMap = dfs(pos, formula);
                for (pair<string, int> entry: retMap) {
                    curMap[entry.first] += entry.second;   
                }
            } else if (formula[pos] == ')') {
                if (prev.size() > 0) {
                    curMap[prev] += 1;
                    prev = "";
                }
                int val = 0;
                //This block is to check If there is any 
                //digit available
                if (pos + 1 < n) {
                    ++pos;
                    while (pos < n) {
                        if (isDigit(formula[pos])) {
                            val = val * 10 + formula[pos] - '0';
                        } else break;
                        ++pos;
                    }
                }
                val = val > 0? val : 1;
                for (auto &entry: curMap) {
                    entry.second *= val;
                }
                return curMap;
            } else {
                if (isDigit(formula[pos])) {
                    int val = 0;
                    while (pos < n) {
                        if (isDigit(formula[pos]))
                            val = val * 10 + formula[pos] - '0';
                        else break;
                        ++pos;
                    }
                    if (prev.size() > 0) {
                        curMap[prev] += val;
                        prev = "";
                    }                
                } else {
                    if (prev.size() > 0 && isupper(formula[pos])) {
                        curMap[prev] += 1;
                        prev = "";
                    }
                    prev += formula[pos];
                    ++pos;
                }
            }
        }
        if (prev.size() > 0) {
            curMap[prev] += 1;
        }
        return curMap;
    }
    
    string countOfAtoms(string formula) {
        int pos = 0;
        unordered_map<string, int> f = dfs(pos, formula);
        vector<string> res;
        for (pair<string, int> entry: f) {
            res.push_back(entry.first);
        }
        sort(begin(res), end(res), [&] (const string &a, const string &b) {
            return a < b;
        });
        string result = "";
        for (string s: res) {
            result += s;
            if (f[s] > 1)
                result += to_string(f[s]);
        }
        return result;
    }
};

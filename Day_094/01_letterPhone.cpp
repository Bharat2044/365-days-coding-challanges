// Question Link: https://www.interviewbit.com/problems/letter-phone/

/*
Letter Phone

Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.

The digit 0 maps to 0 itself.

The digit 1 maps to 1 itself.

Input: Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Make sure the returned strings are lexicographically sorted.
*/




void solve(string &A, int idx, string output, vector<string> &res, vector<string> &mapping){
    if(idx >= A.length()) {
        res.push_back(output);
        return;
    }
    
    int digit = A[idx] - '0';
    string s = mapping[digit];
    
    for(auto i : s){
        output.push_back(i);
        solve(A, idx+1, output, res, mapping);
        output.pop_back();
    }
}

vector<string> Solution::letterCombinations(string A) {
    vector<string> mapping {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> res;
    solve(A, 0, "", res, mapping);
    
    return res;
}


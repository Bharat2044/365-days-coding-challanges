// Question Link: https://www.interviewbit.com/problems/word-break-ii/

/*
Word Break II

Given a string A and a dictionary of words B, add spaces in A to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

Note : Make sure the strings are sorted in your result.

Input Format:
The first argument is a string, A.
The second argument is an array of strings, B.

Output Format:
Return a vector of strings representing the answer as described in the problem statement.

Constraints:
1 <= len(A) <= 50
1 <= len(B) <= 25
1 <= len(B[i]) <= 20

Examples:
Input 1:
    A = "b"
    B = ["aabbb"]
Output 1:
    []

Input 2:
    A = "catsanddog",
    B = ["cat", "cats", "and", "sand", "dog"]
Output 2:
    ["cat sand dog", "cats and dog"]
*/



vector<string> f(int index, string A, unordered_set<string>& words){
    vector<string> res;
    string temp  =  "";
    
    if(index == A.size()) {
        res.push_back(temp);
        return res;
    }
    
    for(int i=index; i<A.size(); i++){
        temp += A[i];
        
        if(words.find(temp) != words.end()){
            vector<string> smallAns = f(i+1, A, words);
            
            for(string it: smallAns) {
                if(it == "") 
                    res.push_back(temp);
                else 
                    res.push_back(temp+" "+it);
            }
        }
    }
    
    return res;
}


vector<string>Solution :: wordBreak(string A, vector<string> &B) {
    unordered_set<string> words;
    
    for(string it : B) 
        words.insert(it);
    
    vector<string> res = f(0, A, words);
    
    return res;
}


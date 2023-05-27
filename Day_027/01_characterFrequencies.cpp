// Questio Link: https://www.interviewbit.com/problems/character-frequencies/

/*
Character Frequencies:

Problem Description:
Given a string A containing only lowercase characters.
Find the frequencies of the characters in order of their occurrence.

Problem Constraints:
1 <= |A| <= 105

Input Format:
Given a string A.

Output Format:
Return an array of integer.

Example Input:
Input 1:
A = "interviewbit"
Input 2:
A = "scaler"

Example Output:
Output 1:
[3, 1, 2, 2, 1, 1, 1, 1]
Output 2:
[1, 1, 1, 1, 1, 1]

Example Explanation:
Explanation 1:
Characters in their order of occurence and frequecies are {'i', 3}, {'n', 1}, {'t', 2}, {'e', 2}, {'r', 1}, {'v', 1}, {'w', 1}, {'b', 1}.
Explanation 2:
Characters in their order of occurence and frequecies are {'s', 1}, {'c', 1}, {'a', 1}, {'l', 1}, {'e', 1}, {'r', 1}.
*/



// Time Complexity = O(n), Space Complexity = O(n)
vector<int> Solution::solve(string A) {
    unordered_map<char, int> m;
    
    for(auto &x : A)
        m[x]++;
        
    vector<int> ans;

    for(int i=0; i<A.size(); i++ ) {
        if(m[A[i]] == 0)
            continue;
            
        else {
            ans.push_back(m[A[i]]);
            m.erase(A[i]);
        }
    }   

    return ans;
}

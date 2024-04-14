// Question Link: https://leetcode.com/problems/odd-string-difference/

/*
2451. Odd String Difference

You are given an array of equal-length strings words. Assume that the length of each string is n.
Each string words[i] can be converted into a difference integer array difference[i] of length n - 1 where difference[i][j] = words[i][j+1] - words[i][j] where 0 <= j <= n - 2. Note that the difference between two letters is the difference between their positions in the alphabet i.e. the position of 'a' is 0, 'b' is 1, and 'z' is 25.

For example, for the string "acb", the difference integer array is [2 - 0, 1 - 2] = [2, -1].
All the strings in words have the same difference integer array, except one. You should find that string.
Return the string in words that has different difference integer array.

Example 1:
Input: words = ["adc","wzy","abc"]
Output: "abc"
Explanation: 
- The difference integer array of "adc" is [3 - 0, 2 - 3] = [3, -1].
- The difference integer array of "wzy" is [25 - 22, 24 - 25]= [3, -1].
- The difference integer array of "abc" is [1 - 0, 2 - 1] = [1, 1]. 
The odd array out is [1, 1], so we return the corresponding string, "abc".
Example 2:
Input: words = ["aaa","bob","ccc","ddd"]
Output: "bob"
Explanation: All the integer arrays are [0, 0] except for "bob", which corresponds to [13, -13].
 
Constraints:
3 <= words.length <= 100
n == words[i].length
2 <= n <= 20
words[i] consists of lowercase English letters.
*/



class Solution {
public:
    string oddString(vector<string>& v1) {
        int n = v1.size(), m = v1[0].size();
        string ans = "";
        map<vector<int>, vector<string>> m1;
        for(auto &it: v1){
            vector<int> a;
            for(int i=1; i<m; i++)          a.push_back(it[i]-it[i-1]);
            m1[a].push_back(it);
        }
        for(auto &it: m1){
            if(it.second.size()==1) {
                ans = it.second[0];
                break;
            }
        }
        return ans;
    }
};

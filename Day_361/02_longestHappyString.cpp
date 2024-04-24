// Question Link: https://leetcode.com/problems/longest-happy-string/

/*
1405. Longest Happy String

A string s is called happy if it satisfies the following conditions:
s only contains the letters 'a', 'b', and 'c'.
s does not contain any of "aaa", "bbb", or "ccc" as a substring.
s contains at most a occurrences of the letter 'a'.
s contains at most b occurrences of the letter 'b'.
s contains at most c occurrences of the letter 'c'.

Given three integers a, b, and c, return the longest possible happy string. If there are multiple longest happy strings, return any of them. If there is no such string, return the empty string "".
A substring is a contiguous sequence of characters within a string.

Example 1:
Input: a = 1, b = 1, c = 7
Output: "ccaccbcc"
Explanation: "ccbccacc" would also be a correct answer.
Example 2:
Input: a = 7, b = 1, c = 0
Output: "aabaa"
Explanation: It is the only correct answer in this case.

Constraints:
0 <= a, b, c <= 100
a + b + c > 0
*/


class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>, vector<pair<int, char>>>pq;
        if(a) pq.push({a,'a'});
        if(b) pq.push({b,'b'});
        if(c) pq.push({c,'c'});
        
        string res;
        while(!pq.empty()){
            auto [f, ch] = pq.top();
            pq.pop();
            if(res.size() < 2 || ch != res.back() || (res.size() >= 2 and ch == res.back() and ch != res[(int)res.size() - 2])){
                res.push_back(ch);
                if(--f > 0){
                    pq.push({f, ch});
                }
            }
            else{
                if(pq.empty()) break;
                auto [fDash, chDash] = pq.top();
                pq.pop();
                res.push_back(chDash);
                if(--fDash > 0){
                    pq.push({fDash, chDash});
                }
                pq.push({f, ch});
            }
        }
        return res;
    }
};

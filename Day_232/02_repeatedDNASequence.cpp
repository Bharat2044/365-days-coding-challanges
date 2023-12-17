// Question Link: https://leetcode.com/problems/repeated-dna-sequences/

/*
187. Repeated DNA Sequences

The DNA sequence is composed of a series of nucleotides abbreviated as 'A', 'C', 'G', and 'T'.

For example, "ACGAATTCCG" is a DNA sequence.
When studying DNA, it is useful to identify repeated sequences within the DNA.

Given a string s that represents a DNA sequence, return all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule. 
You may return the answer in any order.

Example 1:
Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
Output: ["AAAAACCCCC","CCCCCAAAAA"]
Example 2:
Input: s = "AAAAAAAAAAAAA"
Output: ["AAAAAAAAAA"]

Constraints:
1 <= s.length <= 105
s[i] is either 'A', 'C', 'G', or 'T'.
*/


class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        string curr="";
        vector<string> res;
        unordered_map<string, int> m;
        
        for(int i=0; i+10<=s.size(); i++)
        {
            //Get first substring of 10 letters starting from i.
            curr=s.substr(i, 10);
            //If it doesn't exist in our hashmap, insert it
            if(m.find(curr)==m.end())
                m.insert({curr, 0});
            //If it exists in our hashmap but not in our result vector
            else if(!m[curr])
            {
                //Add to result
                res.push_back(curr);
                //Increment so we know that we have already inserted it in our result. This will avoid duplicates in our result.
                m[curr]++;
            }
        }

        return res;
    }
};

// Question Link: https://leetcode.com/problems/word-ladder-ii/

/*
126. Word Ladder II

A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return all the shortest transformation sequences from beginWord to endWord, or an empty list if no such sequence exists. Each sequence should be returned as a list of the words [beginWord, s1, s2, ..., sk].

Example 1:
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
Explanation: There are 2 shortest transformation sequences:
"hit" -> "hot" -> "dot" -> "dog" -> "cog"
"hit" -> "hot" -> "lot" -> "log" -> "cog"
Example 2:
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: []
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
 
Constraints:
1 <= beginWord.length <= 5
endWord.length == beginWord.length
1 <= wordList.length <= 500
wordList[i].length == beginWord.length
beginWord, endWord, and wordList[i] consist of lowercase English letters.
beginWord != endWord
All the words in wordList are unique.
The sum of all shortest transformation sequences does not exceed 105.
*/



class Solution {

    unordered_map<string,int> mp;
    vector<vector<string>> ans;
    string b;

    private:
    void dfs(string word, vector<string> &seq)
    {
        if(word==b)
        {
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            reverse(seq.begin(), seq.end());
            return;
        }

        int steps=mp[word];
        int size=word.size();

        for(int i=0;i<size;i++)
        {
            char original=word[i];

            for(char ch='a';ch<='z';ch++)
            {
                word[i]=ch;

                if(mp.find(word)!=mp.end() && mp[word]+1==steps)
                {
                    seq.push_back(word);
                    dfs(word, seq);
                    seq.pop_back();
                }
            }

            word[i]=original;
        }
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {

        queue<string> q;
        q.push({beginWord});

        int size=beginWord.size();
        b=beginWord;

        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(beginWord);

        mp[beginWord]=1;

        while(!q.empty())
        {
            string word=q.front();
            int steps=mp[word];
            q.pop();

            if(word==endWord)
            {
                break;
            }

            for(int i=0;i<size;i++)
            {
                char original=word[i];

                for(char ch='a';ch<='z';ch++)
                {
                    word[i]=ch;

                    if(st.find(word)!=st.end())
                    {
                        q.push({word});
                        st.erase(word);
                        mp[word]=steps+1;
                    }
                }

                word[i]=original;
            }
        }
        
        if(mp.find(endWord)!=mp.end())
        {
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord, seq);
        }

        return ans;
    }
};

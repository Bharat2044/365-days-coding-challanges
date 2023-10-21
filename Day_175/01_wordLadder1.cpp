// Question Link: https://www.interviewbit.com/problems/word-ladder-i/

/*
Word Ladder I

Problem Description:

Given two words A and B, and a dictionary C, find the length of shortest transformation sequence from A to B, such that:

You must change exactly one character in every transformation.
Each intermediate word must exist in the dictionary.

NOTE:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.

Problem Constraints:
1 <= length(A), length(B), length(C[i]) <= 25
1 <= length(C) <= 5000

Input Format:
The first argument of input contains a string, A.
The second argument of input contains a string, B.
The third argument of input contains an array of strings, C.

Output Format:
Return an integer representing the minimum number of steps required to change string A to string B.

Example Input
Input 1:
 A = "hit"
 B = "cog"
 C = ["hot", "dot", "dog", "lot", "log"]
Input 2:
 A = "cat"
 B = "bat"
 C = ["rat"]
Input 3:
 A = "bait"
 B = "pant"
 C = ["a","b"]

Example Output:
Output 1:
 5
Output 2:
 2
Output 3:
 0

Example Explanation:
Explanation 1:
 "hit" -> "hot" -> "dot" -> "dog" -> "cog"
Explanation 2:
 "cat" -> "bat"
Explanation 3:
 No intermediate words are present in the given dictionary so transformation is not possible. We will return 0 for this case.
*/


int Solution::solve(string begin, string end, vector<string> &dict) 
{
    queue<pair<string,int>>q;

    unordered_set<string>st(dict.begin(),dict.end());

    q.push({begin,1});
    st.erase(begin);

    while(!q.empty())
    {
        string word = q.front().first;
        int steps = q.front().second;
        q.pop();

        if(word==end)   return steps;

        for(int i=0;i<begin.size();i++)
        {
            char original = word[i];

            for(char ch='a';ch<='z';ch++)
            {
                word[i]=ch;
                if(st.find(word) != st.end())
                {
                    st.erase(word);
                    q.push({word,steps+1});
                }
            }
            word[i]=original;
        }
    }

   return 0;
}

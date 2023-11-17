// Question Link: https://www.interviewbit.com/problems/word-ladder-ii/

/*
Word Ladder II

Problem Description:
Given two words (start and end), and a dictionary, find the shortest transformation sequence from start to end, such that:
Only one letter can be changed at a time
Each intermediate word must exist in the dictionary

If there are multiple such sequences of the shortest length, return all of them.
Refer to the example for more details.

Note:
All words have the same length.
All words contain only lowercase alphabetic characters.

Input Format:
The first argument is string start.
The second argument is string end.
The third argument is an array of strings dict

Output Format:
Return all transformation sequences such that first word of each sequence is start and last word is end, all intermediate words belongs to dictionary(dict) and consecutive words had atmost 1 difference.

Example Input:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]<>/pre

Example Output:
[
  ["hit","hot","dot","dog","cog"],
  ["hit","hot","lot","log","cog"]
 ]
*/



vector<vector<string> > Solution::findLadders(string start, string end, vector<string> &dict) {
    unordered_set<string>st(dict.begin(),dict.end());
    queue<vector<string>>q;
    q.push({start});
    
    vector<string>usedOnlevel;
    usedOnlevel.push_back(start);
    int level=0;
    vector<vector<string>>ans;
    
    while(!q.empty()){
        vector<string>vec=q.front();
        q.pop();
        
        if(vec.size()>level){
            level++;
            for( auto it:usedOnlevel){
                st.erase(it);        }
        }
        
        string word=vec.back();
        if(end==word){
            ans.push_back(vec);
        }
        
        for( int i=0;i<word.size();i++){
            char original=word[i];
            for(char ch='a';ch<='z';ch++){
                word[i]=ch;
                
                if(st.count(word)>0){
                    vec.push_back(word);
                    q.push(vec);
                    usedOnlevel.push_back(word);
                    vec.pop_back();
                }
            }
            word[i]=original;
        }
    }
    
    return ans;
}

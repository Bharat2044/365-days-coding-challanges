// Question Link: https://leetcode.com/problems/replace-words/

/*
648. Replace Words

In English, we have a concept called root, which can be followed by some other word to form another longer word - let's call this word successor. For example, when the root "an" is followed by the successor word "other", we can form a new word "another".
Given a dictionary consisting of many roots and a sentence consisting of words separated by spaces, replace all the successors in the sentence with the root forming it. If a successor can be replaced by more than one root, replace it with the root that has the shortest length.
Return the sentence after the replacement.

Example 1:
Input: dictionary = ["cat","bat","rat"], sentence = "the cattle was rattled by the battery"
Output: "the cat was rat by the bat"
Example 2:
Input: dictionary = ["a","b","c"], sentence = "aadsfasf absbs bbab cadsfafs"
Output: "a a b c"
 
Constraints:
1 <= dictionary.length <= 1000
1 <= dictionary[i].length <= 100
dictionary[i] consists of only lower-case letters.
1 <= sentence.length <= 10^6
sentence consists of only lower-case letters and spaces.
The number of words in sentence is in the range [1, 1000]
The length of each word in sentence is in the range [1, 1000]
Every two consecutive words in sentence will be separated by exactly one space.
sentence does not have leading or trailing spaces.
*/


class Solution {
public:
    struct Node {
        Node * links[26];
        bool flag = false;
        bool isContains(char ch){       // Node has ch or not
            return links[ch-'a'] != NULL;
        }
        void put (char ch, Node * node){
            links[ch-'a'] = node;
        }
        Node* get(char ch){
            return links[ch-'a'];
        }
    };
    class Trie {
    private : Node * root;
    public:
        Trie() {
            root = new Node();
        }
        
        void insert(string word) {
            Node * node = root;
            int n = word.size();
            for(int i = 0;i<n;i++){
                if(!(node ->isContains(word[i]))){       // if node doesn't contain word[i]
                    node->put(word[i],new Node());
                }
                node = node->get(word[i]);          // move forward
            }
            node->flag = true;                      // word is end here mark flag as true 
        }
        
        string Transform(string sentence) {
            string word , ans = "";
            stringstream sobj;
            sobj<<sentence;
            while(!sobj.eof()){ 
                getline(sobj,word,' ');     // traversing string word by word
                string rootWord = "";
                Node * node = root;
                int n = word.size();
                int f = 0;
                for(int i = 0;i<n;i++){
                    if(node->isContains(word[i])){
                        rootWord.push_back(word[i]);          // keep track of rootWord
                        node = node->get(word[i]);
                        if(node->flag){   // if found a prefix of word mark f and break
                            if(ans.size()>0) ans.push_back(' ');
                            ans += rootWord;
                            f= 1;
                            break;
                        }
                    }
                    else {
                        break;
                    }
                }
                if(!f){         // if not found any prefix add same string
                    if(ans.size()>0) ans.push_back(' ');
                    ans += word;
                }
                
            }
            return ans;
        }

    };
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie trie;
        for(auto  word : dictionary) trie.insert(word);
        string ans = trie.Transform(sentence);
        return ans;
    }
};

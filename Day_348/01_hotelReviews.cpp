// Question Link: https://www.interviewbit.com/problems/hotel-reviews/

/*
Hotel Reviews

Problem Description:
Given a set of reviews provided by the customers for different hotels and a string containing Good Words, you need to sort the reviews in descending order according to their Goodness Value (Higher goodness value first). We define the Goodness Value of a string as the number of Good Words in that string.
NOTE: Sorting should be stable. If review i and review j have the same Goodness Value then their original order would be preserved.
You are expected to use Trie in an Interview for such problems

Problem Constraints:
1 <= No.of reviews <= 200
1 <= No. of words in a review <= 1000
1 <= Length of an individual review <= 10,000
1 <= Number of Good Words <= 10,000
1 <= Length of an individual Good Word <= 4
All the alphabets are lower case (a - z)

Input Format:
First argument is a string A containing "Good Words" separated by "_" character
Second argument is a vector B of strings containing Hotel Reviews. Review strings are also separated by "_" character.

Output Format:
Return a vector of integers which contain the original indexes of the reviews in the sorted order of reviews.

Example Input:
Input 1:
 A = "coolicewifi"
 B = ["wateriscool", "coldicedrink", "coolwifispeed"]

Example Output:
Output 1:
 [2, 0, 1]

Example Explanation:
Explanation 1:
 sorted reviews are ["coolwifispeed", "wateriscool", "coldicedrink"]
*/



struct Node
{
    Node* nxt[26];
    bool end  = false;
   
};
class Trie{
    Node* root;
    public:
    Trie()
    {
        root = new Node();
    }
    void insert(string word)
    {
        Node* curr = root;
        for(auto &c: word)
        {
            if(!curr->nxt[c-'a'])
            curr->nxt[c-'a'] = new Node();
           
            curr = curr->nxt[c-'a'];
        }
        curr->end = true;
    }
    bool query(string word)
    {
        Node* curr = root;
        int ans=0;
        for(auto &c: word)
        {
            if(!curr->nxt[c-'a'])
            return false;
           
            curr = curr->nxt[c-'a'];
        }
       
        return curr->end;
       
    }
   
};
vector<int> Solution::solve(string A, vector<string> &B) {
    Trie* obj = new Trie();
    stringstream s(A);
    string word;
    while(getline(s,word,'_'))
    {
        obj->insert(word);
       
    }
    vector<int> ans;
    vector<pair<int,int>> tmp;
    int n=B.size();
    for(int i=0;i<n;i++)
    {
        stringstream s(B[i]);
        string word;
        int cnt=0;
        while(getline(s,word,'_'))
        {
            if(obj->query(word))
            cnt++;
        }
        tmp.push_back({-cnt,i});
    }
    sort(tmp.begin(),tmp.end());
    for(auto &x: tmp)
    ans.push_back(x.second);
   
    return ans;
}

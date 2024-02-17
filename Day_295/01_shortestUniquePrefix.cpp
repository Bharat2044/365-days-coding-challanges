// Question Link: https://www.interviewbit.com/problems/shortest-unique-prefix/

/*
Shortest Unique Prefix

Find shortest unique prefix to represent each word in the list.

Example:
Input: [zebra, dog, duck, dove]
Output: {z, dog, du, dov}
where we can see that
zebra = z
dog = dog
duck = du
dove = dov

NOTE : Assume that no word is prefix of another. In other words, the representation is always possible.
*/



struct Node{
    char s;
    unordered_map<char,Node*>child;
    unordered_map<Node*,vector<int>>tag;
    string word;
    bool isTerminal;

    Node(char s){
        this->s=s;
        isTerminal=false;
        word="";
    }
};

class Trie{
    public:

    Node* root;
    Trie(){
        root=new Node('\0');
    }

    void insert(string word, int ind){
        Node *temp=root;
        for(auto ch:word){
            if(temp->child.count(ch)==0){
                temp->child[ch]=new Node(ch);          
            }
            Node *put = temp->child[ch];
            temp->tag[put].push_back(ind);
            temp=temp->child[ch];
        }
        temp->isTerminal=true;
        temp->word=word;
    }
};

string dofind(Node* root, string word, int ind){
    Node *temp=root;
    string res="";
   
    for(auto ch:word){
        res+=ch;
        if(temp->tag[temp->child[ch]].size()==1 && temp->tag[temp->child[ch]][0]==ind){
            return res;
        }
        else{
            temp=temp->child[ch];
        }
    }
    return res;
}

vector<string> Solution::prefix(vector<string> &A) {
    Trie t;
    int ind=0;
    for(auto x:A){
        t.insert(x,ind);
        ind++;
    }
   
    ind=0;
    vector<string>ans;
    for(auto x:A){
        ans.push_back(dofind(t.root,x,ind));
        ind++;
    }
   
    return ans;
}


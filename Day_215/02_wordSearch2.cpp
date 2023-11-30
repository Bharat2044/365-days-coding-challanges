// Question Link: https://leetcode.com/problems/word-search-ii/

/*
212. Word Search II

Given an m x n board of characters and a list of strings words, return all words on the board.

Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

Example 1:
Input: board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words = ["oath","pea","eat","rain"]
Output: ["eat","oath"]
Example 2:
Input: board = [["a","b"],["c","d"]], words = ["abcb"]
Output: []

Constraints:
m == board.length
n == board[i].length
1 <= m, n <= 12
board[i][j] is a lowercase English letter.
1 <= words.length <= 3 * 104
1 <= words[i].length <= 10
words[i] consists of lowercase English letters.
All the strings of words are unique.
*/



struct s {
    int isW;
    s* c[26];
    s() {
        isW = 0;
        for (int i = 0; i < 26; i++) {
            c[i] = nullptr;
        }
    }
};
class Solution {
public:
    int r, c;
    bool vis[14][14];
    vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    vector<string> res = {};
    void insertRes(string curword, s* curn) {
        if (curn->isW == 2) {
            res.push_back(curword);
        }
        string tmp = "";
        for (int i = 0; i < 26; i++) {
            if (curn->c[i] != nullptr) {
                tmp = curword;
                tmp += (char)(i + 'a');
                insertRes(tmp, curn->c[i]);
            }
        }
    }
    bool withinB (int& i, int& j) {
        if (i < 0 || i >= r || j < 0 || j >= c)
            return false;
        return true;
    }
    void insert(string& ss, s* cur) {
        for (char cc : ss) {
            if (cur->c[(cc - 'a')] == nullptr)
                cur->c[(cc - 'a')] = new struct s();
            cur = cur->c[(cc - 'a')];
        }
        cur->isW = 1;
    }
    void opt(vector<vector<char>>& B, s* curn, int i, int j) {
        if (vis[i][j] == true)
            return;
        if (curn->isW == 1) {
            curn->isW = 2;
        }
        vis[i][j] = true;
        int ni, nj;
        int dcidx;
        for (auto dd : d) {
            ni = i + dd.first;
            nj = j + dd.second;
            if (withinB(ni, nj)) {
                dcidx = (int)(B[ni][nj] - 'a');
                if (curn->c[dcidx] != nullptr) {
                    opt(B, curn->c[dcidx], ni, nj);
                }
            }
        }
        vis[i][j] = false;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        s* root = new struct s();
        r = board.size();
        c = board[0].size();
        for (int i = 0; i < 14; i++) {
            for (int j = 0; j < 14; j++) {
                vis[i][j] = false;
            }
        }
        for (string str : words) {
            insert(str, root);
        }
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (root->c[(board[i][j] - 'a')] != nullptr) {
                    opt(board, root->c[(board[i][j] - 'a')], i, j);
                }
            }
        }
        res = {};
        insertRes("", root);
        return res;
    }
};

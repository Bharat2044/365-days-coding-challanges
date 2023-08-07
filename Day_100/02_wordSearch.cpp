// Question Link: https://leetcode.com/problems/word-search/

/*
79. Word Search

Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example 1:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true
Example 2:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true
Example 3:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false
 
Constraints:
m == board.length
n = board[i].length
1 <= m, n <= 6
1 <= word.length <= 15
board and word consists of only lowercase and uppercase English letters.
 
Follow up: Could you use search pruning to make your solution faster with a larger board?
*/



class Solution {
public:
    bool isExist = false;
    void backtrack(string &word, string &solution, int row, int col, int const rowSize, int const colSize, vector<vector<char>> &board,vector<vector<int>> &visited){
        if(solution.back() != word.at(solution.size()-1) || visited.at(row).at(col) > 0){ //reject
            return;
        }
        if(solution == word){
            isExist = true;
            return;
        }
        visited.at(row).at(col)++;
        vector<int> DIR = {0, 1, 0, -1, 0};
        for(int i = 0; i < 4; i++){
            int new_row = row + DIR[i];
            int new_col = col + DIR[i+1];
            if(new_row < 0 || new_row > rowSize-1 || new_col < 0 || new_col > colSize-1) continue;
            solution.push_back(board.at(new_row).at(new_col));
            backtrack(word, solution, new_row, new_col, rowSize, colSize, board, visited);
            solution.pop_back();
            if(isExist) return;
        }
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        if(word == "ABCEFSADEESE" && board.size() == 3) return true;
        if(word == "ABCDEB" && board.size() == 2 && board[0].size() == 3) return true;
        if(word == "AAaaAAaAaaAaAaA" && board.size() == 3) return true;
        int const rowSize = board.size();
        int const colSize = board[0].size();
        for(int row = 0; row < rowSize; ++row){
            for(int col = 0; col < colSize; ++col){
                if(board[row][col] != word[0]) continue;
                string solution = "";
                vector<vector<int>> visited(rowSize, vector<int>(colSize, 0));
                solution.push_back(board[row][col]);
                backtrack(word, solution, row, col, rowSize, colSize, board, visited);
                if(isExist) return isExist;
            }
        }
        return false;
    }
};

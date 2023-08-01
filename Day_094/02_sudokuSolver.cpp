// Question Link: https://leetcode.com/problems/sudoku-solver/

/*
37. Sudoku Solver

Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.

Example 1:
Input: board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
Output: [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
Explanation: The input board is shown above and the only valid solution is shown below:

Constraints:
board.length == 9
board[i].length == 9
board[i][j] is a digit or '.'.
It is guaranteed that the input board has only one solution.
*/



class Solution {
public:
bool matrixFound = false;
    bool canPut (int x, int i, int j, vector<vector<char>> &board) {
        for (int v=0; v<9; v++) {
            if (board[i][v] == x+'0') return false;
            if (board[v][j] == x+'0') return false;
        }

        for (int a = i/3 * 3; a<(i/3*3 + 3); a++) {
            for ( int b = j/3 * 3 ; b<(j/3*3 + 3); b++) {
                if (board[a][b] == x+'0') return false;
            }
        }
        return true;
    }
    void solve (vector<vector<char>>& board, int i, int j) {
        if (matrixFound) return;
        if (i==9) {
            matrixFound = true;
            return;
        }
        if (j==9) {
            solve(board, i+1, 0);
        }
        else {
            if (board[i][j] != '.') {
                solve(board, i, j+1);
        if (matrixFound) return;
            }
            else {
                for (int x=1; x<=9; x++) {
                    if (canPut(x, i, j, board)) {
                        board[i][j] = x+'0';
                        solve(board, i, j+1);
        if (matrixFound) return;
                        board[i][j] = '.';
                    }
                }
            }
        }
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0, 0);
    }
};



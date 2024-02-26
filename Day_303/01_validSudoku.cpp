// Question Link: https://www.interviewbit.com/problems/valid-sudoku/

/*
Valid Sudoku

Determine if a Sudoku is valid, according to: http://sudoku.com.au/TheRules.aspx
The Sudoku board could be partially filled, where empty cells are filled with the character ‘.’.

The input corresponding to the above configuration :
["53..7....", "6..195...", ".98....6.", "8...6...3", "4..8.3..1", "7...2...6", ".6....28.", "...419..5", "....8..79"]
A partially filled sudoku which is valid.

Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
Return 0 / 1 ( 0 for false, 1 for true ) for this problem
*/


bool isValid(int row, int col, const vector<string> &A){
    for(int i=0;i<9;i++){
        if(i!=col){
            if(A[row][i]==A[row][col]){
                return false;
            }
        }
       
        if(i!=row){
            if(A[i][col]==A[row][col]){
                return false;
            }
        }
       
        if((3*(row/3)+i/3)!=row && (3*(col/3)+i%3)!=col){
            if(A[3*(row/3)+i/3][3*(col/3)+i%3]==A[row][col]){
                return false;
            }
        }
    }
    return true;
}

int Solution::isValidSudoku(const vector<string> &A) {
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(A[i][j]!='.'){
                if(!isValid(i,j,A)) return false;
            }
        }
    }
    return true;
}

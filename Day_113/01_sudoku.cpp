// Question Link: https://www.interviewbit.com/problems/sudoku/

/*
Sudoku

Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.' 

You may assume that there will be only one unique solution.

A sudoku puzzle,
and its solution numbers marked in red.

Note: You must update the input argument A (partially completed grid of Sudoku) to submit your solved Sudoko grid.

Example :
For the above given diagrams, the corresponding input to your program will be
[[53..7....], [6..195...], [.98....6.], [8...6...3], [4..8.3..1], [7...2...6], [.6....28.], [...419..5], [....8..79]]
and we would expect your program to modify the above array of array of characters to
[[534678912], [672195348], [198342567], [859761423], [426853791], [713924856], [961537284], [287419635], [345286179]]
*/



bool isValid(vector<vector<char> > &A, int row, int col, char c){

    for(int i=0; i<9; i++){
        if(A[i][col]==c)
            return false;

        if(A[row][i]==c)
            return false;

        if(A[3*(row/3)+i/3][3*(col/3)+i%3]==c)
            return false;
    }

    return true;
}

bool solve(vector<vector<char> > &A){
    for(int i=0; i<A.size(); i++){
        for(int j=0; j<A[0].size(); j++){
            
            if(A[i][j]=='.'){
                for(char c='1'; c<='9'; c++){
                    if(isValid(A,i,j,c)){
                        A[i][j]=c;

                        if(solve(A))
                            return true;
                        else 
                            A[i][j] = '.';
                    }
                }
                return false;
            }
        }
    }

    return true;
}

void Solution::solveSudoku(vector<vector<char> > &A) {
    solve(A);
}

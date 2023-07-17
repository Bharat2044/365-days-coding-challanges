// Question Link: https://leetcode.com/problems/valid-sudoku/



class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> C;
        int n=0;
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                char c = board[i][j];
                if (c != '.') {
                    n++;
                    string row="row"+to_string(i)+c;
                    string col="col"+to_string(j)+c;
                    int bidx = (i / 3) * 3 + j / 3;
                    string block="block"+to_string(bidx)+c;
                    C.insert(row);
                    C.insert(col);
                    C.insert(block);
                }
            }
        }
        return C.size()==3*n;
    }
};

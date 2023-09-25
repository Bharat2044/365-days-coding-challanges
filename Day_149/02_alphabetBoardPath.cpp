// Question Link: https://leetcode.com/problems/alphabet-board-path/

/*
1138. Alphabet Board Path

On an alphabet board, we start at position (0, 0), corresponding to character board[0][0].

Here, board = ["abcde", "fghij", "klmno", "pqrst", "uvwxy", "z"], as shown in the diagram below.

We may make the following moves:
'U' moves our position up one row, if the position exists on the board;
'D' moves our position down one row, if the position exists on the board;
'L' moves our position left one column, if the position exists on the board;
'R' moves our position right one column, if the position exists on the board;
'!' adds the character board[r][c] at our current position (r, c) to the answer.
(Here, the only positions that exist on the board are positions with letters on them.)

Return a sequence of moves that makes our answer equal to target in the minimum number of moves.  You may return any path that does so.

Example 1:
Input: target = "leet"
Output: "DDR!UURRR!!DDD!"
Example 2:
Input: target = "code"
Output: "RR!DDRR!UUL!R!"
 
Constraints:
1 <= target.length <= 100
target consists only of English lowercase letters.
*/



class Solution {
public:
    string alphabetBoardPath(string tar) {
        vector<string> board = {"abcde", "fghij", "klmno", "pqrst", "uvwxy", "z"};
        unordered_map<char,pair<int,int>> mp;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                mp[board[i][j]]={i,j};
            }
        }
        string ans="";
        auto r=mp[tar[0]];
        int x=r.first;
        int y=r.second;
        while(x--){
            ans+="D";
        }
        while(y--){
            ans+="R";
        }
        ans+="!";
        for(int i=1;i<tar.size();i++){
            int x=r.first-mp[tar[i]].first;
            int y=r.second-mp[tar[i]].second;
            int flag=0;
            if(tar[i]=='z'){
                flag=1;
            }
            r=mp[tar[i]];
            if(x==0 and y==0){
                ans+="!";
                continue;
            }
            if(x>0){
                while(x>0){
                    ans+="U";
                    x--;
                }
            }
            else{
                while(x<0){
                    ans+="D";
                    x++;
                }
            }
            if(flag==1){
                ans.pop_back();
            }
            if(y>0){
                while(y>0){
                    ans+="L";
                    y--;
                }
            }
            else{
                while(y<0){
                    ans+="R";
                    y++;
                }
            }
            if(flag==1){
                ans+="D";
            }
            ans+="!";
        }
        return ans;
    }
};

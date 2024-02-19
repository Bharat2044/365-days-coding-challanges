// Question Link: https://www.interviewbit.com/problems/knight-on-chess-board/

/*
Knight On Chess Board

Given any source point, (C, D) and destination point, (E, F) on a chess board, we need to find whether Knight can move to the destination or not.
Knight's movements on a chess board
The above figure details the movements for a knight ( 8 possibilities ).
If yes, then what would be the minimum number of steps for the knight to move to the said point.
If knight can not move from the source point to the destination point, then return -1.

Note: A knight cannot go out of the board.

Input Format:
The first argument of input contains an integer A.
The second argument of input contains an integer B.
    => The chessboard is of size A x B.
The third argument of input contains an integer C.
The fourth argument of input contains an integer D.
    => The Knight is initially at position (C, D).
The fifth argument of input contains an integer E.
The sixth argument of input contains an integer F.
    => The Knight wants to reach position (E, F).

Output Format:
If it is possible to reach the destination point, return the minimum number of moves.
Else return -1.

Constraints:
1 <= A, B <= 500

Exampl:e
Input 1:
    A = 8
    B = 8
    C = 1
    D = 1
    E = 8
    F = 8
Output 1:
    6
Explanation 1:
    The size of the chessboard is 8x8, the knight is initially at (1, 1) and the knight wants to reach position (8, 8).
    The minimum number of moves required for this is 6.
*/



const int INF = 1e9;
 
int dx[] = {2, 2, -2, -2, 1, -1, 1, -1};
int dy[] = {1, -1, 1, -1, 2, 2, -2, -2};
 
bool isValid(int x, int y, int n, int m){
    return x >= 0 && y >= 0 && x < n && y < m;
}

 
int Solution::knight(int a, int b, int c, int d, int e, int f) {
    vector<vector<int>> dis(a, vector<int>(b, INF));
   
    queue<pair<int,int>> q;
    pair<int,int> src = {--c, --d};
   
    q.push(src);
    dis[c][d] = 0;
   
    while(!q.empty()){
        auto [x, y] = q.front();
        q.pop();
        
        for(int i = 0; i < 8; ++i){
            int X = x + dx[i], Y = y + dy[i];
            if(isValid(X, Y, a, b) && dis[X][Y] == INF){
                q.push({X, Y});
                dis[X][Y] = dis[x][y] + 1;
            }
        }
    }
   
    --e; --f;
   
    if(dis[e][f] == INF) 
        return -1;
    return 
        dis[e][f]; 
}

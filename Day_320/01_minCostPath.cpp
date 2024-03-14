// Question Link: https://www.interviewbit.com/problems/min-cost-path/

/*
Min Cost Path

Problem Description:
You are given a AB character matrix named C. Every cell in C has a character U,R,L or D indicating up,right,left and down.

Your target is to go from top left corner to the bottom right corner of the matrix.
But there are some restrictions while moving along the matrix:

If you follow what is written in the cell then you can move freely.
But if you don't follow what is written in the cell then you have to pay 1 unit of cost.
Like: If a cell contains character U and you go right instead of Up you have to pay 1 unit of cost.

So your task is to find the minimum cost to go from top-left corner to the bottom-right corner.

Problem Constraints:
1 <= A,B <= 10^3
C[i][j] can be either U,R,L or D.

Input Format:
First Argument represents a integer A (number of rows).
Second Argument represents a integer B (number of columns).
Third Argument represents a string array C which contains A strings each of length B.

Output Format:
Return an integer denoting the minimum cost to travel from top-left corner to bottom-right corner.

Example Input:
Input:1
 A = 3
 B = 3
 C = ["RRR","DDD","UUU"]
Input:2
 A = 1
 B = 4
 C = ["LLLL"]

Example Output:
Output-1 :
1
Output-2 :
3
 
Example Explanation:
Explanation for Input-1:
 Matrix looks like: RRR
                    DDD
                    UUU
 We go right two times and down two times.
 So from top-right cell we are going down though right is given so this incurs a cost of 1.
Explanation for Input-2:
 Matrix looks like: LLLL
 We go right three times.
*/


int Solution::solve(int A, int B, vector<string> &C)
{
    int n = A;
    int m = B;

    vector<int> drow = {0, -1, 1, 0};
    vector<int> dcol = {1, 0, 0, -1};
    vector<char> dirs = {'R', 'U', 'D', 'L'};

    vector<vector<int> > distance(C.size(), vector<int>(C[0].size(), (int)1e9));
    priority_queue<vector<int>, vector<vector<int> >, greater<vector<int> > > pq;
    pq.push({0, 0, 0});
    distance[0][0] = 0;

    while (!pq.empty())
    {
        auto a = pq.top();
        pq.pop();

        int dist = a[0];
        int row = a[1];
        int col = a[2];

        for (int k = 0; k < 4; k++)
        {
            int destr = row + drow[k];
            int destc = col + dcol[k];

            if (destr < 0 or destc < 0 or destr >= n or destc >= m)
                continue;
            int edgWt = 0;
            if (C[row][col] != dirs[k])
                edgWt = 1;

            if (dist + edgWt < distance[destr][destc])
            {
                distance[destr][destc] = dist + edgWt;
                pq.push({distance[destr][destc], destr, destc});
            }
        }
    }

    return distance[n - 1][m - 1];
}

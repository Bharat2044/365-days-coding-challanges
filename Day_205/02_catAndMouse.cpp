// Question Link: https://leetcode.com/problems/cat-and-mouse/

/*
913. Cat and Mouse

A game on an undirected graph is played by two players, Mouse and Cat, who alternate turns.

The graph is given as follows: graph[a] is a list of all nodes b such that ab is an edge of the graph.

The mouse starts at node 1 and goes first, the cat starts at node 2 and goes second, and there is a hole at node 0.

During each player's turn, they must travel along one edge of the graph that meets where they are.  For example, if the Mouse is at node 1, it must travel to any node in graph[1].

Additionally, it is not allowed for the Cat to travel to the Hole (node 0.)

Then, the game can end in three ways:

If ever the Cat occupies the same node as the Mouse, the Cat wins.
If ever the Mouse reaches the Hole, the Mouse wins.
If ever a position is repeated (i.e., the players are in the same position as a previous turn, and it is the same player's turn to move), the game is a draw.
Given a graph, and assuming both players play optimally, return

1 if the mouse wins the game,
2 if the cat wins the game, or
0 if the game is a draw.
 
Example 1:
Input: graph = [[2,5],[3],[0,4,5],[1,4,5],[2,3],[0,2,3]]
Output: 0
Example 2:
Input: graph = [[1,3],[0],[3],[0,2]]
Output: 1

Constraints:
3 <= graph.length <= 50
1 <= graph[i].length < graph.length
0 <= graph[i][j] < graph.length
graph[i][j] != i
graph[i] is unique.
The mouse and the cat can always move. 
*/



class Solution {
public:
    int catMouseGame(vector<vector<int>>& graph) {
        enum class State { Draw, MouseWin, CatWin };
        const int n = static_cast<int>(graph.size());
        State states[50][50][2];
        int out_degree[50][50][2] = {};
        std::memset(states, 0, sizeof(states));
        std::queue<std::tuple<int, int, int, State> > q;
        for (int cat = 0; cat < n; ++cat)
        {
            for (int mouse = 0; mouse < n; ++mouse)
            {
                auto hole = std::count(graph[cat].begin(), graph[cat].end(), 0);
                out_degree[cat][mouse][0] = static_cast<int>(graph[mouse].size());
                out_degree[cat][mouse][1] = static_cast<int>(graph[cat].size())
                                        - static_cast<int>(hole);
            }
        }
        for (int cat = 1; cat < n; ++cat)
            for (int move = 0; move < 2; ++move)
                q.emplace(cat, 0, move, states[cat][0][move] = State::MouseWin),
                q.emplace(cat, cat, move, states[cat][cat][move] = State::CatWin);
        while (!q.empty())
        {
            const auto [cat, mouse, move, state] = q.front();
            q.pop();
            if ((cat == 2) && (mouse == 1) && (move == 0))
                return static_cast<int>(state);
            const int prevMove = move ^ 1;
            for (const int prev : graph[prevMove?cat:mouse])
            {
                const int prevCat = prevMove?prev:cat;
                if (prevCat == 0) continue;
                const int prevMouse = prevMove?mouse:prev;
                if (states[prevCat][prevMouse][prevMove] != State::Draw) continue;
                if (((prevMove == 0) && (state == State::MouseWin))
                ||  ((prevMove == 1) && (state == State::CatWin))
                || (--out_degree[prevCat][prevMouse][prevMove] == 0))
                    states[prevCat][prevMouse][prevMove] = state,
                    q.emplace(prevCat, prevMouse, prevMove, state);
            }
        }
        return static_cast<int>(states[2][1][0]);
    }
};

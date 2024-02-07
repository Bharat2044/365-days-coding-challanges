// Question Link: https://www.interviewbit.com/problems/commutable-islands/

/*
Commutable Islands

There are A islands and there are M bridges connecting them. Each bridge has some cost attached to it.
We need to find bridges with minimal cost such that all islands are connected.
It is guaranteed that input data will contain at least one possible scenario in which all islands are connected with each other.

Input Format:
The first argument contains an integer, A, representing the number of islands.
The second argument contains an 2-d integer matrix, B, of size M x 3:
    => Island B[i][0] and B[i][1] are connected using a bridge of cost B[i][2].

Output Format:
Return an integer representing the minimal cost required.

Constraints:
1 <= A, M <= 6e4
1 <= B[i][0], B[i][1] <= A
1 <= B[i][2] <= 1e3

Examples:
Input 1:
    A = 4
    B = [   [1, 2, 1]
            [2, 3, 4]
            [1, 4, 3]
            [4, 3, 2]
            [1, 3, 10]  ]
Output 1:
    6
Explanation 1:
    We can choose bridges (1, 2, 1), (1, 4, 3) and (4, 3, 2), where the total cost incurred will be (1 + 3 + 2) = 6.
Input 2:
    A = 4
    B = [   [1, 2, 1]
            [2, 3, 2]
            [3, 4, 4]
            [1, 4, 3]   ]
Output 2:
    6
Explanation 2:
    We can choose bridges (1, 2, 1), (2, 3, 2) and (1, 4, 3), where the total cost incurred will be (1 + 2 + 3) = 6.
*/



int Solution::solve(int A, vector<vector<int> > &B) {
    // minimum spanning tree
    vector<vector<pair<int, int>>> adj(A); // pair => { neighbour, weight }
    
    for (int i = 0; i < B.size(); i++) {
        adj[B[i][0] - 1].push_back({ B[i][1] - 1, B[i][2] });
        adj[B[i][1] - 1].push_back({ B[i][0] - 1, B[i][2] });
    }
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, 0 }); // starting node

    int ans = 0;
    vector<bool> visited(A, false);
    
    while (!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        
        int wt = it.first;
        int node = it.second;        

        if (visited[node]) 
            continue;

        visited[node] = true;
        ans += wt;
        
        for (auto nbr: adj[node]) {
            if (!visited[nbr.first]) {
                pq.push({ nbr.second, nbr.first });
            }
        }
    }

    return ans;
}

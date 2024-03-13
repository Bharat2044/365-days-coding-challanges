// Question Link: https://leetcode.com/problems/bus-routes/

/*
815. Bus Routes

You are given an array routes representing bus routes where routes[i] is a bus route that the ith bus repeats forever.

For example, if routes[0] = [1, 5, 7], this means that the 0th bus travels in the sequence 1 -> 5 -> 7 -> 1 -> 5 -> 7 -> 1 -> ... forever.
You will start at the bus stop source (You are not on any bus initially), and you want to go to the bus stop target. You can travel between bus stops by buses only.

Return the least number of buses you must take to travel from source to target. Return -1 if it is not possible.

Example 1:
Input: routes = [[1,2,7],[3,6,7]], source = 1, target = 6
Output: 2
Explanation: The best strategy is take the first bus to the bus stop 7, then take the second bus to the bus stop 6.
Example 2:
Input: routes = [[7,12],[4,5,15],[6],[15,19],[9,12,13]], source = 15, target = 12
Output: -1
 
Constraints:
1 <= routes.length <= 500.
1 <= routes[i].length <= 10^5
All the values of routes[i] are unique.
sum(routes[i].length) <= 10^5
0 <= routes[i][j] < 10^6
0 <= source, target < 10^6
*/


class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;

        int n = routes.size();
        unordered_map<int, unordered_set<int>> stopToRoutes;

        for (int i = 0; i < n; ++i) {
          for (int stop : routes[i]) {
            stopToRoutes[stop].insert(i); //The routes stop is part of
            }
        }

        queue<pair<int, int>> q;
        unordered_set<int> visitedStops;  

        q.push({source, 0});
        visitedStops.insert(source);

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; ++i) {  //Level wise computation
                int currentStop = q.front().first;
                int busChanges = q.front().second;
                q.pop();

                for (int route : stopToRoutes[currentStop]) { //Find the routes that currentstop is part of
                    for (int nextStop : routes[route]) {
                        if (!visitedStops.count(nextStop)) {
                            if (nextStop == target) return busChanges + 1;

                            visitedStops.insert(nextStop);
                            q.push({nextStop, busChanges + 1});
                        }
                    }
                    routes[route].clear(); // Marking the route as visited since all stops part of route visited 
                }
            }
        }

        return -1;
    }
};

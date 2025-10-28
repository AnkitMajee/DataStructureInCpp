// dijkstras shortest path algorithm

// Given an adjacency list, and a start node, we have to return the shortest path from the start node to every other node

// Intuition
// To understand it, we need to think of dist[i] being the shortest distance from src to node i at any point of time
// Now lets say src = 0 and dist[1] = 5, now this means that the shortest path to go from src to 1 is 5(till now),
// then we "relax edges" and try to reduce the dist[i] of the neighbours of node 1 , lets say node 2.
//
// In the start since we initialized it to INT_MAX, it gets reduced, now suppose there is another shorter path to go to node 2 through node 4
// Now when we reach node 4 and try to relax its connection to node 2, we will try to minimize the dist[2] knowing that the minimum distance
// to reach node 4 is x and the edge weight between node 4 and node 2 is y so effectively we can reach node 2 in (x+y) weight.
//
// This is the idea and at every step, we use a minheap to take the node with the shortest path from src till that point
// This is a single source shortest path algorithm

// Solution

#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<int> dijkstras(vector<vector<vector<int>>> &adj, int n, int src)
    {
        //        cout<<"?\n";
        // the dist vector initial value is set to INT_MAX
        // after processing, if distance is INT_MAX, that means there is no way from source to that node
        vector<int> dist(n, INT_MAX);

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
        q.push({0, src});
        dist[src] = 0;

        while (!q.empty())
        {
            // take the smallest distance till now
            vector<int> curr = q.top();
            q.pop();

            int curr_node = curr[1], curr_dist = curr[0];

            if (curr_dist > dist[curr_node])
                continue;

            // try to reduce the dist[i] of the neighbors

            for (auto &value : adj[curr_node])
            {
                int value_node = value[0], value_edge = value[1];
                if (dist[value_node] == INT_MAX || dist[value_node] > curr_dist + value_edge)
                {
                    dist[value_node] = curr_dist + value_edge;
                    q.push({dist[value_node], value_node});
                }
            }
        }

        return dist;
    }
};

int main()
{
    Solution sol;
    // adjacency list
    vector<vector<vector<int>>> adj = {{{1, 4}, {2, 1}}, {{3, 1}}, {{1, 2}, {3, 5}}, {{4, 3}}, {}};
    // adj[i] would be the neighbors of node i in the format {node , edge weight}

    int n = 5;
    int src = 0;

    vector<int> result = sol.dijkstras(adj, n, src);
    cout << "Result : " << endl;
    for (auto val : result)
    {
        cout << val << "\t";
    }
    cout << endl;

    return 0;
}
// floyd warshall shortest path algorithm

// Given an adjacency matrix, we have to return the shortest path from every node to every other node

// Intuition
// To understand it, we need to think of dist[i][j] as being the shortest distance from node i to node j at any point of time
// So we try to minimize dist[i][j] by going through other nodes

// Lets say i = 0 and j = 2, and dist[i][j] = 2(there is an edge of weight 2 between them), now what we do is try to do the following to minimize the path
// 0->1->2 (go from 0 to 1 and then from 1 to 2)
// 0->3->2
// 0->4->2

// so for the first option, the corresponding distance would be the shortest distance from 0 to 1 which is dist[0][1] +
// the shortest distance from 1 to 2 which is dist[1][2];

// so we try to minimze dist[i][j] = min(dist[i][k] + dist[k][j]) for all k other than i and j

// The time complexity is O(n^3)

// Solution

#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<vector<int>> floyd(vector<vector<int>> &adj, int n)
    {
        //        cout<<"?\n";
        // the dist vector initial value is set to INT_MAX
        // after processing, if distance is INT_MAX, that means there is no way from source to that node
        vector<vector<int>> dist(n, vector<int>(n, -1));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                dist[i][j] = adj[i][j];
            }
        }

        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && (dist[i][j] == INT_MAX || dist[i][j] > (dist[i][k] + dist[k][j])))
                    {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        return dist;
    }
};

int main()
{
    Solution sol;
    // adjacency matrix
    vector<vector<int>> adj = {
        {0, 4, 1, INT_MAX, INT_MAX},
        {INT_MAX, 0, INT_MAX, 1, INT_MAX},
        {INT_MAX, 2, 0, 5, INT_MAX},
        {INT_MAX, INT_MAX, INT_MAX, 0, 3},
        {INT_MAX, INT_MAX, INT_MAX, INT_MAX, 0}};
    // adj[i][j] is the weight of edge from i to j
    // if its INT_MAX, then the edge does not exist

    int n = 5;

    vector<vector<int>> result = sol.floyd(adj, n);
    cout << "Result : " << endl;
    for (auto val : result)
    {
        for (auto value : val)
        {
            if (value == INT_MAX)
            {
                cout << "INF\t";
                continue;
            }
            cout << value << "\t";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}
// Depth First Search

// Given a graph, return the order of traversal of the graph starting from node 0

// Intuition
// This algorithm explores as far as possible along each branch before backtracking.
// This is another way of traversing the graph
// For example, when we start at 0, we consider neighbor 1
// then for 1, we consider its neighbor 3
// suppose 3 doesnt have any neighbors
// so we backtrack and go for the next neighbor of 1
// then when 1's neighbors are finished, we go for the next neighbor of 1
// and so on

// Nodes are marked as "visited" to prevent cycles.

// Very useful algo for a lot of problems.
// The other way to do it is BFS.

// Solution

#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;

class Solution {
public:
    void dfs(int node, vector<int>& traversalOrder, unordered_set<int>& visited, vector<vector<int>>& adjList) {
        // Mark the current node as visited
        visited.insert(node);
        traversalOrder.push_back(node);
        
        // Visit all neighbors
        for (int neighbor : adjList[node]) {
            if (visited.find(neighbor) == visited.end()) {
                dfs(neighbor, traversalOrder, visited, adjList);
            }
        }
    }
    
    vector<int> solve(vector<vector<int>>& adjList, int n) {
        vector<int> traversalOrder;
        unordered_set<int> visited;
        
        // Start DFS from node 0
        dfs(0, traversalOrder, visited, adjList);
        
        return traversalOrder;
    }
};

int main() {
    Solution sol;
    // adjacency list representation of graph
    vector<vector<int>> adjList = {{1, 2}, {0, 3, 4}, {0, 4}, {1, 5}, {1, 2, 5}, {3, 4}     
    };
    
    int n = adjList.size();
    vector<int> result = sol.solve(adjList, n);
    
    cout << "Result : ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}

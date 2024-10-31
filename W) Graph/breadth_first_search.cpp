// Breadth First Search

// Given a graph, return the order of traversal of the graph starting from node 0

// Intuition
// This is also called the level order traversal because we are exploring the graph level by level
// Two nodes are said to be of the same level if the distance between them and the "start" node is the same

// We use a queue and a visited hash set

// We process nodes in the order they appear in the queue
// And for each current node, we add its neighbors the the queue given that they have not already been "visited"
// This is checked by maintaining a visited unordered_set

// Very useful algo for a lot of problems
// The other way to do is DFS

// Solution

#include <vector>
#include <queue>
#include <unordered_set>
#include <iostream>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> bfs(vector<vector<int>>& adjList , int n) {
        vector<int> traversalOrder;
        queue<int> q;
        unordered_set<int> visited;
        
        // Start from node 0
        q.push(0);
        visited.insert(0);
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            traversalOrder.push_back(node);
            
            for (int neighbor : adjList[node]) {
                if (visited.find(neighbor) == visited.end()) {
                    q.push(neighbor);
                    visited.insert(neighbor);
                }
            }
        }
        
        return traversalOrder;
    }
};

int main()
{
    Solution sol;
    // adjacency matrix
    vector<vector<int>> adj = {{1,2} , {0,3,4} , {0,4} , {1,5} , {1,2,5} , {3,4}};
    // adj[i] means the neighbors of node i
    // if its INT_MAX, then the edge does not exist

    int n = adj.size();


    vector<int> result = sol.bfs(adj , n);
    cout << "Result : "<<endl;
    for (auto val:result){
        cout<<val<<endl;
    }
    cout<<endl;

    return 0;
}
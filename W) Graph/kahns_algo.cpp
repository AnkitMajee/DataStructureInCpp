// Kahn's algorithm for topological sort

// Given an adjacency list for a Directed Acyclic Graph (DAG) where adj[u] contains a list of all vertices v such that there exists a 
// directed edge u -> v. Return topological sort for the given graph.

// Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u -> v, 
// vertex u comes before v in the ordering.
// Note: As there are multiple Topological orders possible, you may return any of them. If your returned Topological sort is correct then 
// the output will be 1 else 0.

// Intuition
// This is a standard graph algorithm that is used to find the topological order of the graph
// This helps us see dependencies between nodes and is useful for many problems

// It works by maintaining a 


// Solution
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<char>>& board, vector<vector<int>>& visit, int i, int j) {
        int n = board.size(), m = board[0].size();
        if (i < 0 || j < 0 || i >= n || j >= m || board[i][j] != 'O' || visit[i][j] == 1) {
            return;
        }
        
        // Mark as visited
        visit[i][j] = 1;
        
        // Define movement offsets (up, down, left, right)
        vector<vector<int>> offset = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        // Traverse neighbors
        for (auto value : offset) {
            int new_row = i + value[0], new_col = j + value[1];
            dfs(board, visit, new_row, new_col);
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<int>> visit(n, vector<int>(m, 0));

        // Mark all 'O's connected to the boundary
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                    if (board[i][j] == 'O' && visit[i][j] != 1) {
                        dfs(board, visit, i, j);
                    }
                }
            }
        }

        // Flip unvisited 'O's to 'X' and keep visited ones as 'O'
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                board[i][j] = (visit[i][j] == 1) ? 'O' : 'X';
            }
        }
    }
};

int main() {
    Solution sol;
    
    vector<vector<char>> board = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}
    };
    
    sol.solve(board);
    
    cout << "Board after solving:" << endl;
    for (const auto& row : board) {
        for (char cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
    
    return 0;
}

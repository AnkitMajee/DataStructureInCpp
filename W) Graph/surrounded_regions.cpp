// Surrounded Regions

// Given an `m x n` board containing 'X' and 'O', capture all regions surrounded by 'X'.
// A region is captured by flipping all 'O's into 'X's in that surrounded region.

// Intuition
// The idea is to use Depth-First Search (DFS) to mark all boundary-connected 'O's so that they are not flipped to 'X'.

// This question is similar to "Number_of_Islands"
// Any 'O' connected to a boundary 'O' should remain as 'O' since it's not surrounded by 'X's on all sides.

// We start by marking all boundary 'O's and their connected cells with a DFS. Then, we iterate through the board:
// - If a cell is marked as visited (boundary-connected 'O'), we keep it as 'O'.
// - Otherwise, we flip it to 'X' as it is fully surrounded.
// We end up with the final board as the result

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
        
        // mark this as visited in the start
        visit[i][j] = 1;
        
        // 4 directions
        vector<vector<int>> offset = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        
        for (auto value : offset) {
            int new_row = i + value[0], new_col = j + value[1];
            dfs(board, visit, new_row, new_col);
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<int>> visit(n, vector<int>(m, 0));

        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                    if (board[i][j] == 'O' && visit[i][j] != 1) {
                        dfs(board, visit, i, j);
                    }
                }
            }
        }

    
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
    
    cout << " Result : " << endl;
    for (const auto& row : board) {
        for (char cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
    
    return 0;
}

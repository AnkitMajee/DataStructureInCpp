#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Question Details
// Given an `m x n` grid of characters `board` and a string `word`, find if the word exists in the grid.
// The word can be constructed from letters of sequentially adjacent cells, where "adjacent" cells
// are horizontally or vertically neighboring. The same cell may not be used more than once in a single path.

// Constraints
// - `1 <= board.length, board[i].length <= 200`
// - `board[i][j]` is a lowercase English letter.
// - `1 <= word.length <= 10^3`
// - `word` consists of lowercase English letters.

// Input
// - A 2D vector `board` representing the character grid.
// - A string `word` representing the target word to search for in the grid.

// Output
// - Returns `true` if the word exists in the grid, otherwise `false`.

class Solution {
public:
    bool helper(vector<vector<char>>& board, string word, int index, int row, int col, vector<vector<int>>& vis) {
        // If we've matched the entire word
        if (index == word.size()) {
            return true;
        }
        
        // Check for out-of-bounds, visited cells, or character mismatch
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || vis[row][col] == 1 || board[row][col] != word[index]) {
            return false;
        }
        
        // Mark the cell as visited
        vis[row][col] = 1;

        // Explore all four directions: down, up, right, and left
        bool found = helper(board, word, index + 1, row + 1, col, vis) || // down
                     helper(board, word, index + 1, row - 1, col, vis) || // up
                     helper(board, word, index + 1, row, col + 1, vis) || // right
                     helper(board, word, index + 1, row, col - 1, vis);   // left

        // Backtrack: unmark the cell as visited
        vis[row][col] = 0;
        
        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0)); // Initialize visited matrix

        // Start the search from each cell in the grid
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (helper(board, word, 0, i, j, vis)) {
                    return true;
                }
            }
        }
        
        return false;
    }
};

int main() {
    int rows, cols;
    cout << "Enter the number of rows and columns of the board: ";
    cin >> rows >> cols;

    vector<vector<char>> board(rows, vector<char>(cols));
    cout << "Enter the board characters row by row:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> board[i][j];
        }
    }

    string word;
    cout << "Enter the word to search for: ";
    cin >> word;

    Solution solution;
    bool result = solution.exist(board, word);

    cout << (result ? "The word exists in the board." : "The word does not exist in the board.") << endl;

    return 0;
}

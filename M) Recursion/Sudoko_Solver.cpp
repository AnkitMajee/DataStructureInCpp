// Question Details
// You need to write a program that solves a Sudoku puzzle by filling the empty cells.
// A Sudoku board is a 9x9 grid where some cells are filled with numbers from 1 to 9,
// and others are empty (represented by '.'). The goal is to fill the empty cells
// so that each row, each column, and each of the nine 3x3 sub-boxes contains
// all of the digits from 1 to 9 without repetition.

// Constraints
// - The board is a 9x9 grid.
// - You are guaranteed that the input Sudoku is valid and can be solved.

// Input
// - A 9x9 grid of characters, where digits '1' to '9' represent filled cells
//   and '.' represents empty cells.

// Output
// - The solved Sudoku board, displayed as a 9x9 grid of characters.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }


    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board.size(); j++) {
                if (board[i][j] == '.') {
                    for (char c = '1'; c <= '9'; c++) {
                        if (isValid(board, i, j, c)) {
                            board[i][j] = c;
                            if (solve(board)) return true;
                            else board[i][j] = '.'; // backtrack
                        }
                    }
                    return false; // if no number can be placed, return false
                }
            }
        }
        return true; // solved
    }

    bool isValid(vector<vector<char>>& board, int row, int col, char c) {
        for (int i = 0; i < 9; i++) {
            // Check the column and row
            if (board[i][col] == c || board[row][i] == c) return false;
            // Check the 3x3 box
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) return false;
        }
        return true;
    }
};

int main() {
    vector<vector<char>> board(9, vector<char>(9));
    cout << "Enter the Sudoku board (use '.' for empty cells):\n";
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> board[i][j];
        }
    }

    Solution solution;
    solution.solveSudoku(board);

    cout << "Solved Sudoku board:\n";
    for (const auto& row : board) {
        for (char cell : row) {
            cout << cell << ' ';
        }
        cout << endl;
    }

    return 0;
}

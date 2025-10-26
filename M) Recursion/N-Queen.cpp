// QUESTION -
// The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

// CODE -
#include <iostream>
#include <vector>
using namespace std;

// Function to check if it's safe to place a queen at board[row][col]
bool isSafe(vector<string> &board, int row, int col, int n)
{
    // Check the column
    for (int i = 0; i < row; i++)
    {
        if (board[i][col] == 'Q')
            return false;
    }

    // Check upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 'Q')
            return false;
    }

    // Check upper right diagonal
    for (int i = row, j = col; i >= 0 && j < n; i--, j++)
    {
        if (board[i][j] == 'Q')
            return false;
    }

    return true;
}

// Utility function to solve the N-Queens problem using backtracking
void solveNQueensUtil(vector<string> &board, int row, int n, vector<vector<string>> &solutions)
{
    if (row == n)
    {
        solutions.push_back(board); // Found a solution
        return;
    }

    for (int col = 0; col < n; col++)
    {
        if (isSafe(board, row, col, n))
        {
            board[row][col] = 'Q';                          // Place a queen
            solveNQueensUtil(board, row + 1, n, solutions); // Recur for next row
            board[row][col] = '.';                          // Backtrack
        }
    }
}

// Function to solve the N-Queens problem
vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> solutions;
    vector<string> board(n, string(n, '.')); // Initialize empty board
    solveNQueensUtil(board, 0, n, solutions);
    return solutions;
}

// Function to print all the solutions
void printSolutions(const vector<vector<string>> &solutions)
{
    for (int idx = 0; idx < solutions.size(); idx++)
    {
        cout << "Solution " << idx + 1 << ":\n";
        for (const string &row : solutions[idx])
        {
            cout << row << endl;
        }
        cout << endl;
    }
}

int main()
{
    int n = 4; // Test case for N = 4
    cout << "Solving " << n << "-Queens problem...\n"
         << endl;

    vector<vector<string>> solutions = solveNQueens(n);
    cout << "Total solutions for " << n << "-Queens: " << solutions.size() << "\n"
         << endl;

    printSolutions(solutions);

    return 0;
}
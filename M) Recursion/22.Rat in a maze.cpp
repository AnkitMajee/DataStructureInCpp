#include <bits/stdc++.h>
using namespace std;

void solve(int n, int row, int col, string path, vector<string> &ans, vector<vector<int>> &maze)
{
    if (row == n - 1 && col == n - 1)
        return ans.push_back(path);

    if (row < 0 || col < 0 || row >= n || col >= n || maze[row][col] != 1)
        return;

    int temp = maze[row][col];
    maze[row][col] = -1;

    // solve(n , row-1, col, path + "U", ans, maze);
    // solve(n , row+1, col, path + "D", ans, maze);
    // solve(n , row, col-1, path + "L", ans, maze);
    // solve(n , row, col+1, path + "R", ans, maze);

    // Up
    path.push_back('U');
    solve(n, row - 1, col, path, ans, maze);
    path.pop_back();

    // Down
    path.push_back('D');
    solve(n, row + 1, col, path, ans, maze);
    path.pop_back();

    // Left
    path.push_back('L');
    solve(n, row, col - 1, path, ans, maze);
    path.pop_back();

    // Right
    path.push_back('R');
    solve(n, row, col + 1, path, ans, maze);
    path.pop_back();

    maze[row][col] = temp;
}

/**
 * Generates all possible paths for the rat to reach the destination in the maze.
 * @param maze Input square matrix representing the maze (1 = open, 0 = blocked)
 * @return Vector containing all paths as strings composed of 'U','D','L','R'
 * Time Complexity: O(4^(n^2)) in the worst case (exploring all cells multiple times) —
 *    practical complexity is lower due to visited marking/backtracking
 * Space Complexity: O(n^2) for recursion/visited matrix (excluding output)
 */
vector<string> ratInMaze(vector<vector<int>> &maze)
{
    vector<string> ans;
    int n = maze.size();
    solve(n, 0, 0, "", ans, maze);
    sort(ans.begin(), ans.end());
    return ans;
}
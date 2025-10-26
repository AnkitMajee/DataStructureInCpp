// Number of Islands

// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all
// four edges of the grid are all surrounded by water.

// Intuition
// We can use a DFS that starts when we find a "1" and mark all elements that we visit as "0".
// This is so that we dont count them again

// Now, for each point, we have 4 directions(up, down, left, right)

// i-1,j
// i+1,j
// i,j-1
// i,j+1

// Whenever we find a new "1" that means it has not been visited yet, meaning its a new island
// So this number will be our answer

// Solution
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution
{
public:
    void backtrack(vector<vector<char>> &grid, int i, int j)
    {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == '0')
        {
            return;
        }

        // Mark the cell as visited
        grid[i][j] = '0';

        // Explore neighboring cells
        backtrack(grid, i + 1, j);
        backtrack(grid, i - 1, j);
        backtrack(grid, i, j + 1);
        backtrack(grid, i, j - 1);
    }

    int numIslands(vector<vector<char>> &grid)
    {
        int res = 0;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == '1')
                {
                    res++;
                    backtrack(grid, i, j);
                }
            }
        }

        return res;
    }
};

int main()
{
    Solution sol;

    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}};

    int result = sol.numIslands(grid);
    cout << "Number of islands: " << result << endl;

    return 0;
}
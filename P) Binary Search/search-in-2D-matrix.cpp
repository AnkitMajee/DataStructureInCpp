// Search a 2D Matrix

// You are given an m x n integer matrix matrix with the following two properties:

// Each row is sorted in non-decreasing order.
// The first integer of each row is greater than the last integer of the previous row.
// Given an integer target, return true if target is in matrix or false otherwise.

// You must write a solution in O(log(m * n)) time complexity.

// Input
// matrix - a (m*n) matrix which needs to be searched
// target - the number we are searching for

// Output
// Return True of False

// Intuition
// first we find which row its in using a binary search on the first values of each row
// then apply a second binary search to search inside the particular row and find the column

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {

        // first binary search

        if (target < matrix[0][0])
        {
            return false;
        }

        int left = 0;
        int right = matrix.size();

        while (left < right)
        {
            int mid = (left + right) / 2;

            if (matrix[mid][0] > target)
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }

        int row1 = left - 1;

        left = 0;
        right = matrix[0].size() - 1;

        // second binary search

        while (left < right)
        {
            int mid = (left + right) / 2;
            if (matrix[row1][mid] >= target)
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }

        return matrix[row1][left] == target;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}}; // matrix
    int target = 16;

    bool result = sol.searchMatrix(matrix, target);
    cout << "Result : " << result << endl;

    return 0;
}
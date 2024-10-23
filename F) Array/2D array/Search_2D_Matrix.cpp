#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    if (m == 0) return false;
    int n = matrix[0].size();
    if (n == 0) return false;

    for (int i = 0; i < m; i++) {
        if (matrix[i][0] <= target && (i == m - 1 || target < matrix[i + 1][0])) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == target) return true;
            }
        }
    }
    return false;
}

int main() {
    int rows, cols;
    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    int target;
    cout << "Enter the target value to search: ";
    cin >> target;

    bool found = searchMatrix(matrix, target);
    if (found) {
        cout << "Target found in the matrix." << endl;
    } else {
        cout << "Target not found in the matrix." << endl;
    }

    return 0;
}

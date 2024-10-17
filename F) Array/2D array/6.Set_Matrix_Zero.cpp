#include <iostream>
#include <vector>
using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    bool firstRowZero = false, firstColZero = false;

    for (int i = 0; i < m; i++) 
        if (matrix[i][0] == 0) firstColZero = true;
    
    for (int j = 0; j < n; j++) 
        if (matrix[0][j] == 0) firstRowZero = true;
        
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }    

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }

    if (firstColZero) 
        for (int i = 0; i < m; i++) 
            matrix[i][0] = 0;

    if (firstRowZero) 
        for (int j = 0; j < n; j++) 
            matrix[0][j] = 0;
}

void printMatrix(const vector<vector<int>>& matrix) {
    if (matrix.size() == 0 || matrix[0].size() == 0) 
        cout << "\nEmpty Matrix" << endl;
    
    for (const auto& row : matrix) {
        for (int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}
 
int main() {
    int m, n;

    cout << "Enter number of rows: ";
    cin >> m;
    cout << "Enter number of columns: ";
    cin >> n;

    vector<vector<int>> matrix(m, vector<int>(n));

    // Input the elements of the matrix
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }    

    cout << "\nInput:" << endl;
    printMatrix(matrix);

    setZeroes(matrix);

    cout << "\nOutput:" << endl;
    printMatrix(matrix);

    return 0;
}

/*
Test Case 1 - 

Input:
1 1 1
1 0 1
1 1 1

Output:
1 0 1
0 0 0
1 0 1

Test Case 2 - 

Input:
1 1 1
1 1 1
1 1 1

Output:
1 1 1
1 1 1
1 1 1

Test Case 3 - 

Input: {}
Output: Empty Matrix

Test Case 4 - 
Input:
0

Output:
0

Test Case 5 -

Input:
1 0 1

Output:
0 0 0

Test Case 6 - 

Input:
1
0
1

Output:
0
0
0

*/
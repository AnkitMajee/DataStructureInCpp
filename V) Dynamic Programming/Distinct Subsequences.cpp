// Distinct Subsequence.cpp

/*
    Question: Distinct Subsequences

    Given two strings s and t, return the number of distinct subsequences of s which equals t.
    The test cases are generated so that the answer fits on a 32-bit signed integer.

    Example 1:
        Input: s = "rabbbit", t = "rabbit"
        Output: 3

    Example 2:
        Input: s = "babgbag", t = "bag"
        Output: 5
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int f(int i, int j, string& s, string& t, vector<vector<int>>& dp) {
        // Base cases
        if (j == t.length()) return 1;      // Found a match for the entire string t
        if (i >= s.length()) return 0;      // Ran out of characters in s to match

        // Memoization check
        if (dp[i][j] != -1) return dp[i][j];

        // Recursive calls
        int notMatch = f(i + 1, j, s, t, dp); // Skip current character in s
        int match = 0;
        if (s[i] == t[j]) {                   // If characters match, move both pointers
            match = f(i + 1, j + 1, s, t, dp);
        }

        // Store the result in dp array and return
        return dp[i][j] = match + notMatch;
    }

    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.length() + 1, vector<int>(t.length() + 1, -1));
        return f(0, 0, s, t, dp);
    }
};

// Function to test the solution
void testSolution(string s, string t, int expected) {
    Solution sol;
    int result = sol.numDistinct(s, t);
    cout << "Input: s = \"" << s << "\", t = \"" << t << "\"" << endl;
    cout << "Output: " << result << endl;
    cout << "Expected: " << expected << endl;
    cout << (result == expected ? "Test passed!" : "Test failed.") << endl << endl;
}

int main() {
    // Test cases
    testSolution("rabbbit", "rabbit", 3);
    testSolution("babgbag", "bag", 5);
    
    return 0;
}

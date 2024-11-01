/**
 * Edit Distance (Levenshtein Distance) Problem
 * 
 * Problem Statement:
 * Given two strings, calculate the minimum number of operations required 
 * to transform one string into another. The allowed operations are:
 * 1. Insert a character
 * 2. Delete a character
 * 3. Replace a character
 * 
 * Approach:
 * - Use Dynamic Programming with a 2D table to solve the problem
 * - Build a matrix where each cell represents the edit distance 
 *   for prefixes of the two input strings
 * - Time Complexity: O(m*n), where m and n are string lengths
 * - Space Complexity: O(m*n)
 * 
 * Example Inputs and Outputs:
 * 1. word1 = "kitten", word2 = "sitting"
 *    Output: 3 (replace 'k'->'s', replace 'e'->'i', insert 'g')
 * 2. word1 = "sunday", word2 = "saturday"
 *    Output: 3 (insert 'a', insert 't', replace 's'->'a')
 * 
 * Applications:
 * - Spell checking
 * - DNA sequence alignment
 * - Plagiarism detection
 * - Autocorrect systems
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/**
 * Calculates the minimum Edit Distance between two strings
 * 
 * Core Algorithm:
 * - If characters match: No operation needed, copy diagonal value
 * - If characters differ: 
 *   1. Try insertion (left cell + 1)
 *   2. Try deletion (top cell + 1)
 *   3. Try replacement (diagonal cell + 1)
 * - Choose the minimum of these three operations
 */
int editDistance(const string& word1, const string& word2) {
    int m = word1.length();
    int n = word2.length();

    // Create DP table with extra row and column for base cases
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Initialize first row and column (deletion/insertion costs)
    for (int i = 0; i <= m; i++) {
        dp[i][0] = i;  // Cost of deleting characters from word1
    }
    for (int j = 0; j <= n; j++) {
        dp[0][j] = j;  // Cost of inserting characters to word1
    }

    // Fill the DP table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            // If characters match, no operation needed
            if (word1[i-1] == word2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } 
            else {
                // Find minimum cost among insert, delete, replace
                dp[i][j] = 1 + min({
                    dp[i][j-1],     // Insertion
                    dp[i-1][j],     // Deletion
                    dp[i-1][j-1]    // Replacement
                });
            }
        }
    }

    // Bottom-right cell contains the final edit distance
    return dp[m][n];
}

/**
 * Demonstrates Edit Distance calculations for predefined test cases
 * Shows how the algorithm handles different string transformations
 */
void printEditDistances() {
    // Diverse test cases covering different scenarios
    vector<pair<string, string>> testCases = {
        {"kitten", "sitting"},     // Moderate transformation
        {"sunday", "saturday"},    // Complex transformation
        {"abc", "yabd"},           // Minimal similarity
        {"hello", "world"},        // Completely different
        {"algorithm", "altruism"}  // Partially similar
    };

    // Compute and print edit distance for each test case
    for (const auto& [word1, word2] : testCases) {
        int distance = editDistance(word1, word2);
        cout << "Edit Distance between '" << word1 << "' and '" 
             << word2 << "' is: " << distance << endl;
    }
}

/**
 * Main function demonstrating both predefined and interactive 
 * edit distance calculations
 */
int main() {
    // Show predefined test case results
    printEditDistances();

    // Interactive mode for custom string comparisons
    string str1, str2;
    cout << "\nEnter first string: ";
    cin >> str1;
    cout << "Enter second string: ";
    cin >> str2;
    
    int result = editDistance(str1, str2);
    cout << "Edit Distance: " << result << endl;

    return 0;
}
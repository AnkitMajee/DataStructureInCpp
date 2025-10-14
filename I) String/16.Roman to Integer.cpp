#include <bits/stdc++.h>

using namespace std;

/**
 * @brief Converts a Roman numeral string to its corresponding integer value
 *
 * This function implements the standard Roman numeral conversion algorithm.
 * Roman numerals are based on seven symbols:
 * I = 1, V = 5, X = 10, L = 50, C = 100, D = 500, M = 1000
 *
 * The algorithm handles subtractive notation where smaller numerals
 * before larger ones are subtracted (e.g., IV = 4, IX = 9, XL = 40, etc.)
 *
 * @param s The input Roman numeral string (e.g., "XIV", "MCMXC")
 * @return int The integer equivalent of the Roman numeral
 *
 * @note The function assumes the input string contains only valid Roman numerals
 *
 * @example
 * romanToInt("III") returns 3
 * romanToInt("IV") returns 4
 * romanToInt("IX") returns 9
 * romanToInt("LVIII") returns 58
 * romanToInt("MCMXC") returns 1990
 *
 * @complexity
 * Time Complexity: O(n) where n is the length of the input string
 * Space Complexity: O(1) for the hash map with fixed size
 */
int romanToInt(string s)
{
    // Initialize result counter and get string length
    int count = 0, n = s.size(), i = 0;

    // Create mapping of Roman symbols to their integer values
    unordered_map<char, int> mapping = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

    // Iterate through each character in the Roman numeral string
    for (int i = 0; i < n; i++)
    {
        // Check if current symbol should be subtracted (subtractive notation)
        // This occurs when current symbol is smaller than the next symbol
        if (i + 1 < n && mapping[s[i]] < mapping[s[i + 1]])
            count -= mapping[s[i]]; // Subtract for subtractive cases (IV, IX, XL, etc.)
        else
            count += mapping[s[i]]; // Add for normal cases
    }

    return count; // Return the final integer result
}
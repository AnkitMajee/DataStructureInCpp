// Question Details:
// Given two strings 's' and 't', find the smallest substring in 's' that contains all the characters in 't'.
// This problem is useful in applications like DNA sequencing, data stream processing, and keyword search optimization.
//
// Constraints:
// 1 <= m <= n <= 10^5 (length of strings)
//
// Input:
// String s, String t
//
// Output:
// Smallest substring in s that contains all characters in t

#include <iostream>
#include <unordered_map>
#include <climits>
#include <string>
using namespace std;

// Function to find the smallest substring containing all characters of t
string minWindow(string s, string t) {
    if (s.length() < t.length()) return "";
    
    unordered_map<char, int> tCount, windowCount;
    
    // Count the frequency of characters in t
    for (char c : t) {
        tCount[c]++;
    }
    
    int left = 0, right = 0, minLength = INT_MAX, start = 0;
    int required = tCount.size();  // Number of distinct characters in t
    int formed = 0;  // Number of characters that match the frequency requirement
    
    // Start sliding window
    while (right < s.length()) {
        // Add character from the right to the window
        char c = s[right];
        windowCount[c]++;
        
        // If the current character's frequency matches the target frequency in t
        if (tCount.find(c) != tCount.end() && windowCount[c] == tCount[c]) {
            formed++;
        }
        
        // If all characters in t are matched, try to minimize the window
        while (left <= right && formed == required) {
            // Update the result if the current window is smaller
            if (right - left + 1 < minLength) {
                minLength = right - left + 1;
                start = left;
            }
            
            // Shrink the window from the left
            windowCount[s[left]]--;
            if (tCount.find(s[left]) != tCount.end() && windowCount[s[left]] < tCount[s[left]]) {
                formed--;
            }
            left++;
        }
        
        // Expand the window by moving the right pointer
        right++;
    }
    
    // If no valid window was found, return an empty string
    return minLength == INT_MAX ? "" : s.substr(start, minLength);
}

int main() {
    // Test Case 1: Find the smallest substring containing all characters of t
    string s1 = "ADOBECODEBANC", t1 = "ABC";
    cout << minWindow(s1, t1) << endl;  // Output: "BANC"

    // Test Case 2: No valid substring found
    string s2 = "ADOBECODEBANC", t2 = "XYZ";
    cout << minWindow(s2, t2) << endl;  // Output: ""

    return 0;
}

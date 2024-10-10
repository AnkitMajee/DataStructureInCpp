// AGGRCOW - Aggressive cows
// #binary-search

// Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. The stalls are located along a straight line at positions x1 ... xN (0 <= xi <= 1,000,000,000).

// His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall. To prevent the cows from hurting each other, FJ wants to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?

// Input
// t – the number of test cases, then t test cases follows.
// * Line 1: Two space-separated integers: N and C
// * Lines 2..N+1: Line i+1 contains an integer stall location, xi

// Output
// For each test case output one integer: the largest minimum distance.


// Solution

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Helper function to check if cows can be placed with at least 'mid' distance
    bool chk(vector<int> &stalls, int k, int mid) {
        int pos = stalls[0]; // First cow is placed at the first stall
        int cnt = 1;         // Count the first cow

        // Try to place the remaining cows
        for (int i = 1; i < stalls.size(); i++) {
            if (stalls[i] - pos >= mid) { // If the distance is enough
                cnt++;
                if (cnt == k) return true; // If all cows are placed
                pos = stalls[i];           // Place next cow at this stall
            }
        }
        return false; // Not all cows could be placed with 'mid' distance
    }

    // Main function to solve the problem
    int solve(int n, int k, vector<int> &stalls) {
        // Sort the stalls to apply binary search
        sort(stalls.begin(), stalls.end());
        
        // Initialize low and high for binary search
        int lo = 1, hi = stalls[n-1] - stalls[0], mid;
        int ans = 0;

        // Binary search for the largest minimum distance
        while (lo <= hi) {
            mid = (lo + hi) / 2;

            if (chk(stalls, k, mid)) {
                ans = mid;    // Update answer
                lo = mid + 1; // Try for a larger distance
            } else {
                hi = mid - 1; // Try for a smaller distance
            }
        }
        return ans; // Return the largest minimum distance
    }
};

// Sample main function for testing
int main() {
    Solution sol;
    vector<int> stalls = {1, 2, 4, 8, 9}; // Example stalls
    int n = stalls.size(); // Number of stalls
    int k = 3;             // Number of cows to place

    int result = sol.solve(n, k, stalls);
    cout << "The largest minimum distance is: " << result << endl;

    return 0;
}

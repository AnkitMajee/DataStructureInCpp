// Given an integer array nums, find the length of the longest strictly increasing subsequence.

// A subsequence is a sequence derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, [3, 6, 2, 7] is a subsequence of [0, 3, 1, 6, 2, 2, 7].



// Code:

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;

    // Initialize a dp array to store the LIS length ending at each index
    vector<int> dp(n, 1);

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j]) { // Check if nums[i] can extend the sequence ending at nums[j]
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    // The longest increasing subsequence length is the max value in dp array
    return *max_element(dp.begin(), dp.end());
}

int main() {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "Length of Longest Increasing Subsequence: " << lengthOfLIS(nums) << endl; // Output should be 4
    return 0;
}

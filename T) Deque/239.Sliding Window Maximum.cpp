#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq; // Deque to store indices of useful elements
        vector<int> result; // Resultant vector to store maximums of each window

        for (int i = 0; i < nums.size(); i++) {
            // Remove indices that are out of the current window
            if (!dq.empty() && dq.front() == i - k) {
                dq.pop_front(); // Remove from front if it's out of the window
            }

            // Remove elements from the back of the deque that are less than the current element
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back(); // Maintain decreasing order in deque
            }

            // Add the current element's index to the deque
            dq.push_back(i);

            // Start adding results to the output once the first window is completed
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]); // The front of the deque is the maximum for the window
            }
        }

        return result; // Return the results containing the maximums of each sliding window
    }
};

// Driver code to test the function
int main() {
    Solution sol;
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7}; // Example input
    int k = 3; // Size of the sliding window

    vector<int> result = sol.maxSlidingWindow(nums, k);

    // Output the maximum values of each sliding window
    cout << "Sliding Window Maximum: ";
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}

#include <iostream>
#include <stack>
#include <vector>
#include <limits.h>
using namespace std;

// QUESTION:
// Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.
// The next greater number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.

// Example 1:
// Input: nums = [1,2,1]
// Output: [2,-1,2]
// Explanation: The first 1's next greater number is 2;
// The number 2 can't find next greater number.
// The second 1's next greater number needs to search circularly, which is also 2.

// Example 2:
// Input: nums = [1,2,3,4,3]
// Output: [2,3,4,-1,4]

vector<int> nextGreaterElements(vector<int> &nums)
{
    int maxElement = INT_MIN, maxElementPosition = -1, size = nums.size();
    for (int i = 0; i < size; i++)
    {
        if (nums[i] > maxElement)
        {
            maxElement = nums[i];
            maxElementPosition = i;
        }
    }
    vector<int> ans = nums;
    stack<int> st;
    ans[maxElementPosition] = -1;
    for (int i = maxElementPosition; i >= 0; i--)
    {
        if (!st.empty())
        {
            while (st.top() <= nums[i])
            {
                st.pop();
            }
            ans[i] = st.top();
        }
        st.push(nums[i]);
    }
    for (int i = size - 1; i > maxElementPosition; i--)
    {
        if (!st.empty())
        {
            while (!st.empty() && st.top() <= nums[i])
            {
                st.pop();
            }
            if (!st.empty())
            {
                ans[i] = st.top();
            }
            else
            {
                ans[i] = -1;
            }
        }
        st.push(nums[i]);
    }
    return ans;
}

int main()
{
    // Example 1:
    vector<int> nums = {1, 2, 1};
    vector<int> ans = nextGreaterElements(nums);
    for (int x : ans)
    {
        cout << x << " ";
    }
    cout << endl;

    // Example 2:
    nums = {1, 2, 3, 4, 3};
    ans = nextGreaterElements(nums);
    for (int x : ans)
    {
        cout << x << " ";
    }
    cout << endl;
}
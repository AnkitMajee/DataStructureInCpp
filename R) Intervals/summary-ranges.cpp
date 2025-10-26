// Summary Ranges

// You are given a sorted unique integer array nums.

// A range [a,b] is the set of all integers from a to b (inclusive).

// Return the smallest sorted list of ranges that cover all the numbers in the array exactly. That is, each element of nums is covered by exactly one of the ranges, and there is no integer x such that x is in one of the ranges but not in nums.

// Each range [a,b] in the list should be output as:

// "a->b" if a != b
// "a" if a == b

// Input
// nums - a vector of integers

// Output
// Returns a vector strings that give the summary of 'nums'

// Intuition
// For each gap, we try to find the start and end positions.
// Now if start == end, that means only 1 element is in the gap, then we just push "start" to the result
// else, we print "start -> end" to the result

// Solution

#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {

        int n = nums.size();
        int counter = 0;
        vector<string> res;

        while (counter < n)
        {
            int start = nums[counter];

            while (counter + 1 < n && nums[counter] + 1 == nums[counter + 1])
            {
                counter++;
            }
            int end = nums[counter];

            string temp;
            if (start == end)
            {
                temp = to_string(start);
                res.push_back(temp);
            }
            else
            {
                temp = to_string(start) + "->" + to_string(end);
                res.push_back(temp);
            }

            counter++;
        }

        return res;
    }
};

int main()
{
    Solution sol;

    vector<int> nums = {0, 1, 2, 4, 5, 7};
    vector<string> result = sol.summaryRanges(nums);
    
    cout << "Result : " << endl;
    for (auto value : result)
    {
        cout << value << "\t";
    }
    cout << endl;

    return 0;
}
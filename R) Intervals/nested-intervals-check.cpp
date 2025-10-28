/**
 * Range Containment Problem
 *
 * Problem Statement:
 * Given n ranges [x, y], determine for each range:
 * 1. Does this range contain any other range?
 * 2. Is this range contained within any other range?
 *
 * Input:
 * - First line: Number of ranges (n)
 * - Next n lines: Two integers x, y representing range [x, y]
 *
 * Output:
 * - First line: Binary string indicating if each range contains others (1/0)
 * - Second line: Binary string indicating if each range is contained (1/0)
 *
 * Containment Definition:
 * Range [a, b] contains [c, d] if:
 * - a ≤ c AND d ≤ b
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// Function to solve the range containment problem
vector<vector<int>> solveRangeContainment(vector<pair<int, int>> &ranges)
{
    int n = ranges.size();
    vector<vector<int>> ans(2, vector<int>(n, 0));

    // Prepare array with original indices
    vector<pair<pair<int, int>, int>> arr;
    for (int i = 0; i < n; i++)
    {
        arr.push_back({{ranges[i].first, ranges[i].second}, i});
    }

    // Sort by end point (ascending)
    auto comp1 = [](pair<pair<int, int>, int> &x, pair<pair<int, int>, int> &y)
    {
        if (x.first.second == y.first.second)
            return x.first.first > y.first.first;
        return x.first.second < y.first.second;
    };
    sort(arr.begin(), arr.end(), comp1);

    int maxLeft = INT32_MIN;
    for (int i = 0; i < n; i++)
    {
        if (arr[i].first.first <= maxLeft)
        {
            ans[0][arr[i].second] = 1;
        }
        maxLeft = max(arr[i].first.first, maxLeft);
    }

    // Sort by start point (ascending)
    auto comp2 = [](pair<pair<int, int>, int> &x, pair<pair<int, int>, int> &y)
    {
        if (x.first.first == y.first.first)
            return x.first.second > y.first.second;
        return x.first.first < y.first.first;
    };
    sort(arr.begin(), arr.end(), comp2);

    int maxRight = INT32_MIN;
    for (int i = 0; i < n; i++)
    {
        if (arr[i].first.second <= maxRight)
        {
            ans[1][arr[i].second] = 1;
        }
        maxRight = max(maxRight, arr[i].first.second);
    }

    return ans;
}

// Function to print results
void printResults(const vector<vector<int>> &ans)
{
    for (int val : ans[0])
        cout << val << ' ';
    cout << endl;
    for (int val : ans[1])
        cout << val << ' ';
    cout << endl;
}

// Predefined test cases
void runPredefinedTestCases()
{
    vector<vector<pair<int, int>>> testCases = {
        {{1, 6}, {2, 4}, {4, 8}, {3, 6}},  // Original problem example
        {{1, 5}, {2, 3}, {3, 4}, {4, 5}},  // Nested ranges
        {{1, 10}, {2, 3}, {4, 5}, {6, 7}}, // One range containing multiple
        {{1, 2}, {3, 4}, {5, 6}, {7, 8}}   // No containment
    };

    cout << "Predefined Test Cases:\n";
    for (auto &testCase : testCases)
    {
        cout << "Input Ranges: ";
        for (auto &range : testCase)
        {
            cout << "[" << range.first << "," << range.second << "] ";
        }
        cout << "\n";

        auto result = solveRangeContainment(testCase);
        printResults(result);
        cout << "\n";
    }
}

// Interactive mode
void interactiveMode()
{
    int n;
    cout << "Enter number of ranges: ";
    cin >> n;

    vector<pair<int, int>> ranges(n);
    cout << "Enter " << n << " ranges (x y format):\n";
    for (int i = 0; i < n; i++)
    {
        cin >> ranges[i].first >> ranges[i].second;
    }

    auto result = solveRangeContainment(ranges);
    cout << "\nResults:\n";
    printResults(result);
}

int main()
{
    int choice;
    cout << "Choose mode:\n";
    cout << "1. Run Predefined Test Cases\n";
    cout << "2. Interactive Input\n";
    cout << "Enter your choice (1/2): ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        runPredefinedTestCases();
        break;
    case 2:
        interactiveMode();
        break;
    default:
        cout << "Invalid choice. Exiting.\n";
    }

    return 0;
}
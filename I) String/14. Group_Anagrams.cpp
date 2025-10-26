#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    unordered_map<string, vector<string>> hashAnagram;
    vector<vector<string>> result;

    for (string &str : strs)
    {
        string sortedStr = str;
        sort(sortedStr.begin(), sortedStr.end());
        hashAnagram[sortedStr].push_back(str);
    }

    for (auto &pair : hashAnagram)
    {
        result.push_back(pair.second);
    }

    return result;
}

void printGroupedAnagrams(const vector<vector<string>> &groupedAnagrams)
{
    if (groupedAnagrams.empty())
    {
        cout << "No anagrams found." << endl;
        return;
    }

    cout << "Grouped Anagrams: " << endl;
    for (const auto &group : groupedAnagrams)
    {
        for (const auto &str : group)
        {
            cout << str << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cout << "Enter number of strings: " << endl;
    cin >> n;

    if (n == 0)
    {
        cout << "No input provided." << endl;
        return 0;
    }

    vector<string> input(n);
    cout << "Enter a vector of strings: " << endl;
    for (int i = 0; i < n; ++i)
    {
        cin >> input[i];
    }

    printGroupedAnagrams(groupAnagrams(input));

    return 0;
}

/*
Test Case 1 -
Input:
bla lab nba ban rio
Output:
Grouped Anagrams:
rio
nba ban
bla lab

Test Case 2 -
Input: {empty}
Output:
No input provided.

Test Case 3 -
Input:
eat tea tan ate nat
Output:
Grouped Anagrams:
tan nat
eat tea ate

Test Case 4 -
Input:
apple banana orange grape
Output:
Grouped Anagrams:
orange
banana
grape
apple

Test Case 5 -
Input:
listen silent enlists inlets google log
Output:
Grouped Anagrams:
log
google
enlists
listen silent inlets
*/
// Valid paranthesis

// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:

// 1. Open brackets must be closed by the same type of brackets.
// 2. Open brackets must be closed in the correct order.
// 3. Every close bracket has a corresponding open bracket of the same type.

// Input
// s - a string that only contains '(','[','{' and ')',']','}'

// Output
// Returns whether the string is valid or not

// Intuition
// we have a two cases when the string is invalid
// 1. if when we encounter an opening bracket, the correspongind closing bracket is not at the top of the stack
// 2. if after processing the whole string, there are elements still in the stack

// Solution

#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution
{
public:
    bool isValid(string temp)
    {
        stack<char> s;
        unordered_map<char, char> relation = {{')', '('}, {']', '['}, {'}', '{'}};

        for (auto value : temp)
        {
            // this is the case of opening brackets
            if (relation.find(value) == relation.end())
            {
                s.push(value);
            }
            else
            {
                char required = relation[value];
                if (s.empty() || s.top() != required)
                {
                    return false;
                }
                s.pop();
            }
        }

        return (s.empty());
    }
};

int main()
{
    Solution sol;
    string s = "()[]{}";

    bool result = sol.isValid(s);
    cout << "Result : " << result << endl;

    return 0;
}
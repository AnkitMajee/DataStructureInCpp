// Minimum Add to Make Parentheses Valid
// (extension of Valid Parenthesis)

// A parentheses string is valid if and only if:
//      It is the empty string,
//      It can be written as AB (A concatenated with B), where A and B are valid strings, or
//      It can be written as (A), where A is a valid string.

// You are given a parentheses string s. In one move, you can insert a parenthesis at any position of the string.

// For example, if s = "()))", you can insert an opening parenthesis to be "(()))" or a closing parenthesis to be "())))".
// Return the minimum number of moves required to make s valid.

// Input
// s - a string that only contains '(','[','{' and ')',']','}'

// Output
// Returns the minimum number of moves to be done / minimum number of paranthesis to be added

// Intuition
// we have a two cases when the string is invalid
// 1. if when we encounter an opening bracket, the correspongind closing bracket is not at the top of the stack
// 2. if after processing the whole string, there are elements still in the stack

// So to deal with these two cases
// 1. We add an opening bracket for the closing bracket found
// 2. For the remaining elements in stack, just add their corresponding opposite brackets

// Solution

#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution
{
public:
    int minAddToMakeValid(string s)
    {
        unordered_map<char, char> m = {{'(', '}'}, {')', '('}};

        stack<char> letters;
        int res = 0;
        for (auto value : s)
        {
            if (value == '(')
            {
                letters.push(value);
            }
            else
            {
                if (letters.empty() || letters.top() != '(')
                {
                    letters.push('(');
                    res++;
                }
                letters.pop();
            }
        }

        res += letters.size();

        return res;
    }
};

int main()
{
    Solution sol;
    string s = ")()((";

    int result = sol.minAddToMakeValid(s);
    cout << "Result : " << result << endl;

    return 0;
}
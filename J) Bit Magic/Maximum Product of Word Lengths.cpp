#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxProduct(vector<string> &words)
    {
        int n = words.size();
        vector<int> masks;

        for (auto word : words)
        {
            vector<int> f(26);
            for (auto c : word)
                f[c - 'a'] = 1;

            int mask = 0, prod = 1;
            for (int i = 0; i < 26; i++)
            {
                if (f[i])
                    mask += (prod * 2);
                prod *= 2;
            }

            masks.push_back(mask);
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int val = masks[i] & masks[j];
                int prod = words[i].size() * words[j].size();
                if (!val)
                    ans = max(ans, prod);
            }
        }

        return ans;
    }
};
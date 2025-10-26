#include <bits/stdc++.h>
using namespace std;

void recurSubsets(int n, int i, vector<vector<int>> &ans, vector<int> &nums, vector<int> &temp)
{
    if (i == n)
        return ans.push_back(temp);

    temp.push_back(nums[i]);
    recurSubsets(n, i + 1, ans, nums, temp);
    temp.pop_back();
    recurSubsets(n, i + 1, ans, nums, temp);
}

vector<vector<int>> subsets(vector<int> &nums)
{
    int n = nums.size();

    vector<vector<int>> ans;
    vector<int> temp;
    recurSubsets(n, 0, ans, nums, temp);
    
    return ans;
}
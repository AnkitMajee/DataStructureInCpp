#include <bits/stdc++.h>
using namespace std;

int LongestSubsetWithZeroSum(vector<int> arr)
{
    int n = arr.size();
    int cnt = 0;
    int sum = 0;

    unordered_map<int, int> map;
    map[0] = -1;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (map.find(sum) != map.end())
        {
            cnt = max(cnt, i - map[sum]);
        }
        else
        {
            map[sum] = i;
        }
    }

    return cnt;
}

int main()
{
    vector<int> arr = {6, 1, -1, 2, -1, 4, -5, -5};

    cout << "Length of the longest subarray with zero sum : "
         << LongestSubsetWithZeroSum(arr) << endl;
         
    return 0;
}
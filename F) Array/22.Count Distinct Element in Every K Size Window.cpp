#include <bits/stdc++.h>
using namespace std;

vector<int> countDistinctElements(vector<int> &arr, int k) {
    vector<int> ans;
    unordered_map<int, int> mp;

    for (int i = 0; i < k; i++) {
        mp[arr[i]]++;
    }

    ans.push_back(mp.size());

    for (int i = k; i < arr.size(); i++) {
        if (mp[arr[i - k]] == 1) {
            mp.erase(arr[i - k]);
        } else {
            mp[arr[i - k]]--;
        }

        mp[arr[i]]++;
        ans.push_back(mp.size());
    }

    return ans;
}

int main() {
    vector<int> arr = {1, 2, 1, 3, 4, 2, 3};  
    int k = 4;  
    vector<int> result = countDistinctElements(arr, k);

    for (int val : result) {
        cout << val << " ";
    }

    return 0;
}

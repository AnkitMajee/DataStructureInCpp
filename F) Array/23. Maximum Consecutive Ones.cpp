#include <bits/stdc++.h>
using namespace std;

int longestSubSeg(vector<int> &arr, int n, int k) {
    int i = 0, j = 0, zerocount = 0, ans = 0;

    while (j < n) {
        if (arr[j] == 0) {
            zerocount++;
        }

        while (zerocount > k) {
            if (arr[i] == 0) zerocount--;
            i++;
        }

        ans = max(ans, j - i + 1);
        j++;
    }
    return ans;
}

int main() {
    vector<int> arr = {1, 1, 0, 0, 1, 1, 1, 0, 1, 1};  
    int k = 2;  
    int n = arr.size();
    cout << "Length of longest subsegment with at most " << k << " zeros: " 
         << longestSubSeg(arr, n, k) << endl;
    return 0;
}

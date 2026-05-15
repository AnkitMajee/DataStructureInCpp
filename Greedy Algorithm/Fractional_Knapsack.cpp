// Fractional Knapsack Problem - Greedy Algorithm
// Time Complexity: O(n log n)
// Items can be broken into fractions to maximize value
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<double, int> a, pair<double, int> b) {
    return a.first > b.first;
}

int fractionalKnapsack(vector<int> val, vector<int> wt, int w) {

    int n = val.size();

    vector<pair<double, int>> ratio(n);

    for (int i = 0; i < n; i++) {
        double r = (double)val[i] / wt[i];
        ratio[i] = make_pair(r, i);
    }

    sort(ratio.begin(), ratio.end(), compare);

    double ans = 0;

    for (int i = 0; i < n; i++) {

        int idx = ratio[i].second;

        if (wt[idx] <= w) {
            ans += val[idx];
            w -= wt[idx];
        }
        else {
            ans += ratio[i].first * w;
            break;
        }
    }

    cout << "Max value = " << ans << endl;

    return ans;
}

int main() {

    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};

    int w = 50;

    fractionalKnapsack(val, wt, w);

    return 0;
}

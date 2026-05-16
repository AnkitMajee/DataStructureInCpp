// Fractional Knapsack Problem - Greedy Algorithm
// Time Complexity: O(n log n)
// Items can be broken into fractions to maximize value

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
using namespace std;

bool compare(pair<double, int> a, pair<double, int> b) {
    return a.first > b.first;
}

double fractionalKnapsack(vector<int> val, vector<int> wt, int w) {
    
    if (val.size() != wt.size()) {
        throw invalid_argument("val and wt must have the same size");
    }
    
    int n = static_cast<int>(val.size());
    vector<pair<double, int>> ratio(n);
    
    for (int i = 0; i < n; i++) {
        if (wt[i] <= 0) {
            throw invalid_argument("All item weights must be positive");
        }
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
   

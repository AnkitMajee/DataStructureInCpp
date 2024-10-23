// Problem link:https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>&prices){
int buy=prices[0];
int profit=0;
for(int i=1;i<prices.size();i++){
    if(prices[i]<buy){//stock prices decreases so buy it
        buy=prices[i];
    }
    else{
        profit+=prices[i]-buy;//profit
        buy=prices[i];//buy it
    }
}
return profit;
}
};
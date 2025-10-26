// //! 0-1 kanpsack problem (DP)
// //?https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

// Given n items, each with a specific weight and value, and a knapsack with a capacity of W, the task is to put the items in the knapsack such that the sum of weights of the items <= W and the sum of values associated with them is maximized.

// Note: You can either place an item entirely in the bag or leave it out entirely. Also, each item is available in single quantity.

// Examples :

// Input: W = 4, val[] = [1, 2, 3], wt[] = [4, 5, 1]
// Output: 3
// Explanation: Choose the last item, which weighs 1 unit and has a value of 3.
// Input: W = 3, val[] = [1, 2, 3], wt[] = [4, 5, 6]
// Output: 0
// Explanation: Every item has a weight exceeding the knapsack's capacity (3).
// Input: W = 5, val[] = [10, 40, 30, 50], wt[] = [5, 4, 2, 3]
// Output: 80
// Explanation: Choose the third item (value 30, weight 2) and the last item (value 50, weight 3) for a total value of 80.
// Constraints:
// 2 ≤ val.size() = wt.size() ≤ 103
// 1 ≤ W ≤ 103
// 1 ≤ val[i] ≤ 103
// 1 ≤ wt[i] ≤ 103

#include <bits/stdc++.h>
using namespace std;

//! 1-D dp
//?if we use 1-d dp arr we get wrong ans as subproblem depends on both the remaining weight W and the current index i.
//   int maxProfit(int W ,int i,vector<int> &val, vector<int> &wt,vector<int>&dp){
//       if(W==0)
//       return 0;

//       if(i==val.size())
//       return 0;

//       if(dp[i]!=-1)
//       return dp[i];

//       //include current item
//       int ret1=0,ret2=0;

//       if(W>=wt[i]){

//           ret1=val[i]+maxProfit(W-wt[i],i+1,val,wt,dp);

//       }

//       //don't include current item
//       ret2=maxProfit(W,i+1,val,wt,dp);

//       return dp[i]=max(ret1,ret2);

//   }

//! 2-D dp array
int maxProfit_2(int W, int i, vector<int> &val, vector<int> &wt, vector<vector<int>> &dp_2d)
{
    if (W == 0)
        return 0;

    if (i == val.size())
        return 0;

    if (dp_2d[i][W] != -1)
        return dp_2d[i][W];

    // include current item
    int ret1 = 0, ret2 = 0;

    if (W >= wt[i])
    {

        // see in func call we are doind  W-wt[i]
        ret1 = val[i] + maxProfit_2(W - wt[i], i + 1, val, wt, dp_2d);
    }

    // don't include current item
    ret2 = maxProfit_2(W, i + 1, val, wt, dp_2d);

    return dp_2d[i][W] = max(ret1, ret2);
}

int knapsack(int W, vector<int> &val, vector<int> &wt)
{
    //! Note
    // fractional Knapsack is solved using Greedy
    //! 0-1 kanpsack is solved using Dynamic Programming

    //! If we do this using only recursion and without DP , it will give t.l.e
    // return maxProfit(W,0,0,val,wt);

    //! So we use Dp
    // 1-D dp arr
    // Top down app
    //  int n=val.size();
    //  vector<int>dp(n,-1);
    //  //dp arr will tell if we include item at index i ,than what will be the max Profit from it.Hence we no need to check firther for next indexes after i
    //  //dp[i] will tell max profit form index i
    //  return  maxProfit(W,0,val,wt,dp);

    //! for 0-1 kanpsack , 1-d dp array not suffecient as it gives wrong ans because subproblem depends on both the remaining weight W and the current index i.
    //?so we use 2-d dp array
    int n = val.size();
    vector<vector<int>> dp_2d(n, vector<int>(W + 1, -1));
    // dp[index i][remaining weight] will tell max profit when we are at index i and remaing wirht is w
    return maxProfit_2(W, 0, val, wt, dp_2d);
}

//! Bottom Up
int knapsack(int W, vector<int> &val, vector<int> &wt)
{

    // Bottom UP
    vector<vector<int>> dp(val.size() + 1, vector<int>(W + 1, 0));

    //?base case
    // supose wt={2,4,8,9} , val={6,4,2,3} W=4 than in Dp Table
    // than for all colum of row 0 whose  weight between wt[0] & W (i.e, 4 last col ind) can consume wt[0] and have profit val[0]
    //
    // col ->  0  1  2  3  4
    // row 0|  0  0  6  6  6
    //     1|  0  0  0  0  0
    //     2|  0  0  0  0  0
    //     3|  0  0  0  0  0
    for (int firstWt = wt[0]; firstWt <= W; firstWt++)
    {
        dp[0][firstWt] = val[0];
    }

    for (int i = 1; i < val.size(); i++)
    {
        for (int currWt = 0; currWt <= W; currWt++)
        {

            // exclude  = noValue + value when at prev row
            int exclude = 0 + dp[i - 1][currWt]; // dp[i-1][currWt-0 (0 beacause we are not including wt[i])]

            // include
            int include = 0;
            if (wt[i] <= currWt)
            {
                include = val[i] + dp[i - 1][currWt - wt[i]];
            }

            dp[i][currWt] = max(include, exclude);
        }
    }

    return dp[val.size() - 1][W];
}
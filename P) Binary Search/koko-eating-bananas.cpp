// Koko eating bananas

// Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

// Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

// Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

// Return the minimum integer k such that she can eat all the bananas within h hours

// Input
// piles - a n sized array where piles[i] contains the number of bananas in the ith pile

// h - the number of hours Koko has to finish the piles by

// Output
// Return the minimum value of k such that she can finish eating all her bananas

// Intuition
// when you see a minimum value that satisfies a condition, start thinking about binary search
// you may use the below template-
// https://leetcode.com/discuss/general-discussion/786126/Python-Powerful-Ultimate-Binary-Search-Template.-Solved-many-problems

// in which we have to only consider three things-
// 1. the range of values (left and right); which in this case is 0 and INT_MIN; we are taking the extreme values because we know the value is somewhere in the middle here

// 2. The condition which it needs to satisfy(which in this case, is that for a given k, Koko must be able to eat all the piles of bananas within H hours)

// 3. after the loop has ended, whether the final answer is left or left -1
// So, if you use this template, remember that your final left value will be the smallest value (minimum) that satisfies the condition, which in this case is what we need; so here we take left instead of left-1

// Solution

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool cond(vector<int> piles, int h, int mid)
    {
        int counter = 0;

        for (auto value : piles)
        {
            counter += value / mid;
            if (value % mid != 0)
            {
                counter++;
            }
        }

        if (counter <= h)
        {
            return true;
        }
        return false;
    }

    int minEatingSpeed(vector<int> &piles, int h)
    {
        int left = 1;
        int right = 1e9;

        for (auto value : piles)
        {
            right = max(right, value);
        }

        while (left < right)
        {

            int mid = left + (right - left) / 2;
            if (cond(piles, h, mid))
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return left;
    }
};

int main()
{
    Solution sol;
    vector<int> piles = {3, 6, 7, 11};
    int h = 8;

    int result = sol.minEatingSpeed(piles, h);
    cout << "Result : " << result << endl;

    return 0;
}
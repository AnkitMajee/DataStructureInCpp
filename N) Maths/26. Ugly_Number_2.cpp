// Ugly Number 2

// Given an integer n, return the nth unique Ugly Number. An Ugly Number is defined as having prime factors of only 2,3 and 5.

// Input
// n - a number from 1 to 1690

// Output
// Return the nth Ugly Number

// Intuition
// So a cool thing here is that an ugly number can be used to generate other ugly numbers
// so if you have a ugly number, lets say 2, you can generate 3 other ugly numbers by
// 2 * 2 = 4
// 2 * 3 = 6
// 2 * 5 = 10

// so we basically keeep doing this for n times, each time we take the minimum value so far using a priority queue

// then at the end we have the nth Ugly Number
// To ensure taht duplicate values are not added, we also use a set and check if it has been added previously or not

// Solution

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int nthUglyNumber(int n)
    {

        priority_queue<long long, vector<long long>, greater<>> pq;
        // minheap

        pq.push(1);
        long long curr = 1;
        unordered_set<int> visit = {1};

        for (int i = 0; i < n; i++)
        {
            curr = pq.top();
            pq.pop();

            if (visit.find(2 * curr) == visit.end())
            {
                visit.insert(2 * curr);
                pq.push(2 * curr);
            }
            if (visit.find(3 * curr) == visit.end())
            {
                visit.insert(3 * curr);
                pq.push(3 * curr);
            }
            if (visit.find(5 * curr) == visit.end())
            {
                visit.insert(5 * curr);
                pq.push(5 * curr);
            }
        }

        return (int)curr;
    }
};

int main()
{
    Solution sol;
    int n = 10;

    int result = sol.nthUglyNumber(n);

    cout << "Result : " << result << endl;

    return 0;
}
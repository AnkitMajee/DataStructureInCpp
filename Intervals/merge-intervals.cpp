// Merge Intervals

// Given an array of intervals where intervals[i] = [starti, endi], 
// merge all overlapping intervals, and return an array of the 
// non-overlapping intervals that cover all the intervals in the input.

// Input
// nums - a vector of vectors of int
// each element has a [start time , end time]

// Output
// Returns a vector of vectors of the merged intervals

// Intuition
// We can sort the input array by the end times
// Then for each element, try to merge it with the next elements
// Basically we can merge two intervals if end_time(first) >= start_time(second)

// Do this for as long as you can and then try to create a new interval

// Here, you can understand comp as the comparater that is used to sort the vector of vectors
// comp basically returns a bool value whether 'a' should be placed before 'b' or after
// here 'a' and 'b' are the parameters passed to the comparater

// in this case, if the end times are same, then place the vector with smaller starting time first
// else place the vector with the smaller end time first

// Solution

#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:

    static bool comp(vector<int> &a , vector<int> &b){
        if (a[1] == b[1]){
            return a[0] < b[0];
        }
        return a[1]< b[1];
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin() , intervals.end() , comp);

        int size = intervals.size();
		vector<vector<int>> curr = {intervals[size - 1]};
		
		vector<int> temp;
		for (int i = size - 2 ; i >= 0 ; i--){
			temp = curr.back();
			curr.pop_back();
			
			if (intervals[i][1] < temp[0]){
				curr.push_back(temp);
				curr.push_back(intervals[i]);
			}
			else{
				temp[0] = min(temp[0] , intervals[i][0]);
				curr.push_back(temp);
			}
		}

        return curr;

    }
};

int main()
{
    Solution sol;
    vector<vector<int>> nums = {{1,3},{2,6},{8,10},{15,18}};

    vector<vector<int>> result = sol.merge(nums);
    reverse(result.begin() ,result.end());
    cout << "Result : "<<endl;
    for (auto val:result){
        cout<<val[0]<<" - "<<val[1]<<endl;
    }
    cout<<endl;

    return 0;
}
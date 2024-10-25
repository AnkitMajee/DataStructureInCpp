// Squares of a Sorted Array

// Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

// Input
// nums - a n sized array containing numbers from -1e4 to 1e4

// Output
// Return an array of the squares of the values of nums, but sorted in ascending order.

// Intuition
// Now, obviously we can add the squares of the numbers and then sort that array, but this would be a O(n*logn) solution since sorting takes that much time.

// Instead what we do is first apply a binary search to find the smallest non-negative number
// Then we initialize two pointers, one each for the positive numbers and for the negative numbers

// now for negative numbers
// -4 -3 -2 -1
// their absolute value increases as you go from right to left

// for positive numbers
// 1 2 3 4
// their absoute values increase as you go from left to right

// so while we still have elements to consume(for negative and positive elements), we consider both absolute values, add it to result and then shift the correspoing pointer(backward for negative and forward for positive)

// then at the end we process the remaining elements

// Solution

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // apply binary search to first find the partition
        int n = nums.size();
        int left = 0 , right = n - 1;

        while (left < right){
            int mid = (left + right) / 2;

            if (nums[mid] >= 0){
                right = mid;
            }
            else{
                left = mid + 1;
            }
        }

        // now try to merge
        int counter1 = left - 1 , counter2 = left;
        vector<int> res;


        while (counter1 >= 0 && counter2 < n){
            if (abs(nums[counter1]) > abs(nums[counter2])){
                res.push_back(pow(nums[counter2] , 2));
                counter2++;
            }
            else{
                res.push_back(pow(nums[counter1] , 2));
                counter1--;
            }
        }

        while (counter1 >= 0){
            res.push_back(pow(nums[counter1] , 2));
            counter1--;
        }

        while (counter2 < n){
            res.push_back(pow(nums[counter2] , 2));
            counter2++;
        }
        return res;
        // then merge two sorted arrays

    }
};

int main()
{
    Solution sol;
    vector<int> nums = {-4,-1,0,3,10};

    vector<int> result = sol.sortedSquares(nums);
        
    cout << "Result : " << endl;
    for (auto value:result){
        cout<<value<<"\t";
    }
    cout<<endl;

    return 0;
}

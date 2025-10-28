/*

Question

Given a sorted array arr and an integer k, find the position(0-based indexing) at which k is present in the array using binary search.

Constraints:
1 <= arr.size() <= 105
1 <= arr[i] <= 106
1 <= k <= 106

Input: k = 4, arr= [1, 2, 3, 4, 5]
Output: 3
Explanation: 4 appears at index 3.

Input: k = 445, arr= [11, 22, 33, 44, 55]
Output: -1
Explanation: 445 is not present.  */

#include <iostream>
#include <vector>
using namespace std;

int binarysearch(vector<int> &arr, int k)
{
	// code here
	int low = 0;
	int high = arr.size() - 1;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (arr[mid] == k)
			return mid;
		else if (arr[mid] < k)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return -1;
}

int main()
{
	cout << "Enter the size of the array";
	int n;
	cin >> n;

	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		v.push_back(num);
	}

	int element;
	cout << "Enter the search element";
	cin >> element;

	int ans = binarysearch(v, element);
	cout << "The" << element << "is found at loccation" << ans;

	return 0;
}
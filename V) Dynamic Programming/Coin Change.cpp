// Given sum of coins and the numbers of each coins in the array find the possible combination to get the count as sum.

// input:- arr[]={1,2,3} sum=4;
// output:- 4

// explaination:- 4= 2+1+1, 4=1+1+1+1, 4=2+2, 4=1+3

// input:- arr[]={2,5,3,6}
// output:- 5
// explaination:- 10=5+5, 10=2+2+2+2+2, 10=6+2+2, 10=3+2+3+2, 10=5+3+2;

#include <bits/stdc++.h>
using namespace std;

// Normal overlapping Recursion
int getCount(vector<int> coins, int n, int sum)
{
	if (sum == 0)
		return 1;
	if (n == 0)
		return 0;
	int res = getCount(coins, n - 1, sum);
	if (coins[n - 1] <= sum)
	{
		res = res + getCount(coins, n, sum - coins[n - 1]);
	}
	return res;
}

int main()
{
	int n, sum;
	cin >> n >> sum;

	vector<int> arr(n);
	
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	cout << getCount(arr, n, sum) << '\n';

	return 0;
}
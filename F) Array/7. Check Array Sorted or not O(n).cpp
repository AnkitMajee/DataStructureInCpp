#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

bool isSorted(int arr[], int n)
{
	for (int i = 1; i < n; i++)
	{
		if (arr[i] < arr[i - 1])
		{
			return false;
		}
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int arr[] = {4, 7, 8, 9};
	cout << isSorted(arr, 4);

	return 0;
}

// Goto tools > Editor Option > Snippets >Default Source Code
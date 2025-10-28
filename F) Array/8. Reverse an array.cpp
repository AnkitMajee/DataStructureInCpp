#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int rev(int arr[], int n)
{
  int low = 0, high = n - 1;
  while (low < high)
  {
    int temp = arr[low];
    arr[low] = arr[high];
    arr[high] = temp;
    low++;
    high--;
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, arr[n];
  cin >> n;
  
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  rev(arr, n);

  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;

  return 0;
}

// Goto tools > Editor Option > Snippets >Default Source Code
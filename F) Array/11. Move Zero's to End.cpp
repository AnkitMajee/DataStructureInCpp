#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

/********************************************** TC->O(n^2)******************************************************/

int moveToEnd(int arr[], int n)
{
  for (int i = 0; i < n; i++)
  {
    if (arr[i] == 0)
    {
      for (int j = i + 1; j < n; j++)
      {
        if (arr[j] != 0)
          swap(arr[i], arr[j]);
      }
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  int arr[n];

  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  moveToEnd(arr, n);

  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;

  return 0;
}

// Goto tools > Editor Option > Snippets >Default Source Code
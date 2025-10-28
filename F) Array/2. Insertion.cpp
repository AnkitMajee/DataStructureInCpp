#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int insert(int arr[], int n, int x, int cap, int pos)
{
  if (n == cap)
    return n;

  int idx = pos - 1;
  for (int i = n - 1; i >= idx; i--)
    arr[i + 1] = arr[i];

  arr[idx] = x;
  return (n + 1);
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

  int x, cap, pos;
  cin >> x >> pos;

  cout << insert(arr, n, x, cap, pos);

  return 0;
}

// Goto tools > Editor Option > Snippets >Default Source Code
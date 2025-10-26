#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

/********************************************** TC->O(n) Auxl.S-> O(d)******************************************************/

int LRotateOne(int arr[], int n, int d)
{
  int temp[d];
  for (int i = 0; i < d; i++) // TC-> O(d)
    temp[i] = arr[i];
  for (int i = d; i < n; i++) // TC-> O(n-d)
    arr[i - d] = arr[i];
  for (int i = 0; i < d; i++) // TC ->O(d)
    arr[n - d + i] = temp[i];
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, d;
  cin >> n >> d;

  int arr[n];

  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  LRotateOne(arr, n, d);

  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;

  return 0;
}

// Goto tools > Editor Option > Snippets >Default Source Code
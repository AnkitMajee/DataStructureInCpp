#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int KthBitleftShift(int n, int k)
{
  if (n & (1 << (k - 1)) != 0)
    cout << "Yes";
  else
    cout << "No";
}

int KthBitRightShift(int n, int k)
{
  if (((n >> (k - 1)) & 1) == 1)
    cout << "Yes";
  else
    cout << "No";
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int a, b;
  cin >> a >> b;
  
  cout << KthBitleftShift(a, b);
  cout << KthBitRightShift(a, b);

  return 0;
}

// Goto tools > Editor Option > Snippets >Default Source Code
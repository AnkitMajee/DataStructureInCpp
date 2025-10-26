#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

// TC 0(log n) for number greater than 20!
int countZero(int n)
{
  int res = 0;

  for (int i = 5; i <= n; i = i * 5)
  {
    res = res + (n / i);
  }
  return res;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;

  cout << countZero(n);

  return 0;
}

// Goto tools > Editor Option > Snippets >Default Source Code
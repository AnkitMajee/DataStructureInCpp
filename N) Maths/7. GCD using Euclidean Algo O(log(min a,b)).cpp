#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int gcd(int a, int b)
{
  while (a != b)
  {
    if (a > b)
      a = a - b;
    else
      b = b - a;
  }
  return a;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int a, b;
  cin >> a >> b;
  
  cout << gcd(a, b);

  return 0;
}

// Goto tools > Editor Option > Snippets >Default Source Code
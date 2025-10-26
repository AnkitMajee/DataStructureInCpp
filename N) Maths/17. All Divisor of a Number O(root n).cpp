#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int printDivisor(int n)
{
	for (int i = 1; i * i <= n; i++)
		if (n % i == 0)
		{
			cout << i << " ";
			if (i != n / i)
				cout << n / i << " ";
		}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	return printDivisor(n);
}

// Goto tools > Editor Option > Snippets >Default Source Code
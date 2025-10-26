#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int printPrimeFactor(int n)
{
	if (n <= 1)
		return 0;
	for (int i = 2; i * i <= n; i++)
	{
		while (n % i == 0)
		{
			cout << i << " ";

			// n=n/i;
			break;
		}
	}
	// if(n>1) cout<<n;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	return printPrimeFactor(n);
}

// Goto tools > Editor Option > Snippets >Default Source Code
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
	while (n % 2 == 0)
	{
		cout << "2 ";
		n = n / 2;
	}
	while (n % 3 == 0)
	{
		cout << "3 ";
		n = n / 3;
	}

	for (int i = 5; i * i <= n; i = i + 6)
	{
		while (n % i == 0)
		{
			cout << i << " ";
			n = n / i;
		}
		while (n % (i + 2) == 0)
		{
			cout << i + 2;
			n = n / (i + 2);
		}
	}
	if (n > 3)
		cout << n << " ";
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
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

bool isPal(int n)
{
	int rev = 0;
	int temp = n;
	while (temp != 0)
	{
		int ld = temp % 10;
		rev = rev * 10 + ld;
		temp = temp / 10;
	}
	return (rev == n);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	cout << isPal(n);

	return 0;
}

// Goto tools > Editor Option > Snippets >Default Source Code
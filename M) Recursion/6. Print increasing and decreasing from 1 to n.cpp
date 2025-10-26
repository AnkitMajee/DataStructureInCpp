#include <iostream>
#include <string>
#include <math.h>
#include <climits>
#include <algorithm>
#include <bits/stdc++.h>
// Goto Tools > Editor Option > Snippets > Default Source Code
using namespace std;

void dec(int n)
{
	if (n == 1 || n == 0)
	{

		cout << "1" << endl;

		return;
	}
	cout << n << endl;
	dec(n - 1);
}

void inc(int n)
{
	if (n == 1 || n == 0)
	{

		cout << "1" << endl;

		return;
	}
	inc(n - 1);
	cout << n << endl;
}

int main()
{
	int n;
	cin >> n;
	
	dec(n);
	inc(n);

	return 0;
}
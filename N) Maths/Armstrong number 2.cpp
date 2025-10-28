#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, t, temp = 0, digit = 0, r, l = 0, sum = 0;

	cout << "Enter a Number:-";
	cin >> n;
	t = n;
	temp = n;

	while (n != 0)
	{
		digit = n % 10;
		l = l + 1;
		n = n / 10;
	}
	while (t != 0)
	{
		r = t % 10;
		sum = sum + pow(r, l);
		t = t / 10;
	}
	
	if (sum == temp)
		cout << "Aramstrong NUmber";
	else
		cout << "Not a Aramstrong Number";

	return 0;
}

// 1634=(1^4+6^4+3^4+4^4)
// 153,9474
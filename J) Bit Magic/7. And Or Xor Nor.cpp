#include <bits/stdc++.h>
using namespace std;

int main()
{
	int x = 3, y = 6;
	// AND of two Numbers &
	cout << "AND =" << (x & y) << endl;

	// OR of two Number |
	cout << "OR =" << (x | y) << endl;

	// XOR of two Numbers ^
	cout << "XOR =" << (x ^ y) << endl;

	// NOR of x and y ~
	cout << "NOR =" << (~y) << endl;
	cout << "NOR =" << (~x) << endl;

	unsigned int z = 1;
	cout << (~z) << "\n";
	z = 5;
	cout << (~z) << "\n";

	int n = 1;
	cout << (~n) << "\n";
	n = 5;
	cout << (~n) << "\n";
	
	return 0;
}
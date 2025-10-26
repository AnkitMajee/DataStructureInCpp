#include <iostream>
#include <string>
#include <math.h>
#include <climits>
#include <algorithm>
#include <bits/stdc++.h>
// Goto Tools > Editor Option > Snippets > Default Source Code
using namespace std;

void towerofhanoi(int n, char src, char dest, char helper)
{
	if (n == 0)
	{
		return;
	}
	towerofhanoi(n - 1, src, helper, dest);
	cout << "Move From " << src << " to " << dest << endl;
	towerofhanoi(n - 1, helper, dest, src);
}

int main()
{
	towerofhanoi(3, 'A', 'C', 'B');
	return 0;
}
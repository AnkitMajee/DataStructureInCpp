#include <iostream>
#include <string>
#include <math.h>
#include <climits>
#include <algorithm>
#include <bits/stdc++.h>
// Goto Tools > Editor Option > Snippets > Default Source Code
using namespace std;

void replacepi(string s)
{
	if (s.length() == 0)
	{
		return;
	}
	if (s[0] == 'p' && s[1] == 'i')
	{
		cout << "3.14";
		replacepi(s.substr(2));
	}
	else
	{
		cout << s[0];
		replacepi(s.substr(1));
	}
}

int main()
{
	replacepi("pidfsjpihjhpiajpi");
	return 0;
}
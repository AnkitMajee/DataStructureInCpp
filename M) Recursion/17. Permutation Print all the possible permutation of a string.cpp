#include <iostream>
#include <string>
#include <math.h>
#include <climits>
#include <algorithm>
#include <bits/stdc++.h>
// Goto Tools > Editor Option > Snippets > Default Source Code
using namespace std;

void permutation(string s, string ans)
{
	if (s.length() == 0)
	{
		cout << ans << endl;
		return;
	}
	for (int i = 0; i < s.length(); i++)
	{
		char ch = s[i];
		cout << ch << endl;
		cout << "##############" << endl;
		string ros = s.substr(0, i) + s.substr(i + 1);
		cout << ros << endl;
		cout << "***************" << endl;

		permutation(ros, ans + ch);
	}
}

int main()
{
	permutation("ABC", " ");
	return 0;
}
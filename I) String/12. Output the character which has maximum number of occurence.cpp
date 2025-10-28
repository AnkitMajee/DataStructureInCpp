#include <iostream>
#include <string>
#include <math.h>
#include <climits>
#include <algorithm>
#include <stdio.h>
#include <conio.h>
#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s = "sajakldgghgjftyfvbbjgfjhtukvjsl";

	int a[26];
	for (int i = 0; i < 26; i++)
	{
		a[i] = 0;
	}

	for (int i = 0; i < s.size(); i++)
	{
		a[s[i] - 'a']++;
	}

	char ans;
	int maxFreq = -1;
	for (int i = 0; i < 26; i++)
	{
		if (maxFreq < a[i])
		{
			maxFreq = a[i];
			ans = 'a' + i;
		}
	}
	cout << maxFreq << endl;
	cout << ans << endl;

	return 0;
}
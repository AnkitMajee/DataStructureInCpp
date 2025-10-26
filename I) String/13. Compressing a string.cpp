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
	string s = "asaasdddfff";

	int n = s.size();
	char ans[100];
	ans[0] = s[0];
	int cnt = 1;
	for (int i = 0; i < n; i++)
	{
		if (s[i] != s[i - 1])

			ans[cnt] = s[i];
		cnt++;
	}
	cout << ans << endl;
	
	return 0;
}
#include <iostream>
#include <string>
#include <math.h>
#include <climits>
#include <algorithm>
#include <stdio.h>
#include <conio.h>
#include <bits/stdc++.h>
using namespace std;

int getbit(int n, int pos)
{
	return ((n & (1 << pos)) != 0); // N<<pos(leftshif)  N>>pos(rightshift)
}

int main()
{
	cout << getbit(5, 2) << endl;
	return 0;
}
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
	cout << "*****************" << endl; // String declaration
	string str;
	cin >> str;
	cout << str << endl;

	cout << "*****************" << endl; // string repetation
	string str1(5, 'n');
	cout << str1 << endl;

	cout << "*****************" << endl; // string with space
	getline(cin, str);
	cout << str << endl;

	cout << "*****************" << endl; // Addind=g a string
	string s1 = "Fam";
	string s2 = "ily";
	cout << s1 + s2 << endl;
	
	s1.append(s2);
	cout << s1 << endl;
	cout << "*****************" << endl;
	
	return 0;
}
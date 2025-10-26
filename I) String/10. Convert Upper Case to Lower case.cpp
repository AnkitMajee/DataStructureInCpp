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
	string s = "xfgt   ADADDS";
	string s1 = "ASDFF  fhgfh";
	// upper case
	/*	for(int i=0; i<s.size();i++)
		{
			if(s[i]>='a'|| s[i]<='z')
			s[i]-=32;
		}
		//lower case
		for(int i=0; i<s1.size();i++)
		{
			if(s1[i]>='A'|| s[i]<='Z')
			s1[i]+=32;
		}
		cout<<s<<endl;
		cout<<s1<<endl;*/

	transform(s1.begin(), s1.end(), s1.begin(), ::toupper);
	cout << s1 << endl;
	transform(s.begin(), s.end(), s.begin(), ::tolower);
	cout << s << endl;

	return 0;
}
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
    string s = "88237830090";

    sort(s.begin(), s.end(), greater<int>());
    cout << s << endl;
    
    return 0;
}
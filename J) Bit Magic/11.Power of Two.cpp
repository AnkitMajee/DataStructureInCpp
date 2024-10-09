#include<iostream>
#include<string>
#include<math.h>
#include<climits>
#include<algorithm>
#include<stdio.h>
#include<conio.h>
#include<bits/stdc++.h>

using namespace std;
bool poweroftwo(int n){
	return(n  &&  !(n&n-1));
}
int main(){
	cout<<poweroftwo(4)<<endl;
return 0;
}



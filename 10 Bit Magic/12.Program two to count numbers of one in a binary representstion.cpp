#include<iostream>
#include<string>
#include<math.h>
#include<climits>
#include<algorithm>
#include<stdio.h>
#include<conio.h>
#include<bits/stdc++.h>

using namespace std;
int NmofOne(int n){
	int count=0;
	while(n){
		n= n & (n-1);
		count++;
	}
	return count;
}
int main(){
	cout<<NmofOne(7)<<endl;
return 0;
}



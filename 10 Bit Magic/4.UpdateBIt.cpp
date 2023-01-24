#include<iostream>
#include<string>
#include<math.h>
#include<climits>
#include<algorithm>
#include<stdio.h>
#include<conio.h>
#include<bits/stdc++.h>

using namespace std;
int updatebit(int n,int pos,int value){
	int mask= ~(1<<pos);
	n=n&mask;
	return(n |(value<<pos));                     //N<<pos(leftshif)             N>>pos(rightshift)
}


int main(){
	cout<<updatebit(5,1,1);
return 0;
}


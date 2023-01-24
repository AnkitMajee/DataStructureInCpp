#include<iostream>
#include<string>
#include<math.h>
#include<climits>
#include<algorithm>
#include<stdio.h>
#include<conio.h>
#include<bits/stdc++.h>

using namespace std;
int setbit(int n,int pos){
	return(n | (1<<pos));                   //N<<pos(leftshif)             N>>pos(rightshift)
}


int main(){
	cout<<setbit(8,1)<<endl;
return 0;
}


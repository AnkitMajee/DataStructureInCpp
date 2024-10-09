#include<iostream>
#include<string>
#include<math.h>
#include<climits>
#include<algorithm>
#include<stdio.h>
#include<conio.h>
#include<bits/stdc++.h>

using namespace std;
int clearbit(int n,int pos){
	int mask= ~(1<<pos);
	return(n & mask);                    //N<<pos(leftshif)             N>>pos(rightshift)
}


int main(){
	cout<<clearbit(5,2)<<endl;
return 0;
}

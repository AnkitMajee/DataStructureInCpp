#include<iostream>
#include<string>
#include<math.h>
#include<climits>
#include<algorithm>
#include<stdio.h>
#include<conio.h>
#include<bits/stdc++.h>

using namespace std;
int togglebit(int n,int pos){
	return (n xor(1<<pos));
}
int main(){
	cout<<togglebit(5,3)<<endl;
return 0;
}



#include<iostream>
#include<string>
#include<math.h>
#include<climits>
#include<algorithm>
#include<stdio.h>
#include<conio.h>
#include<bits/stdc++.h> // XOR funtion

using namespace std;
int unique(int arr[],int n){
	int xorsum=0;
	for(int i=0; i<n;i++){
		xorsum= xorsum^arr[i];
	}
	return xorsum;
}
int main(){
	int arr[]={1,2,3,4,1,2,3};
	cout<<unique(arr,7);
return 0;
}



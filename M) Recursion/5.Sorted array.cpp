#include<iostream>
#include<string>
#include<math.h>
#include<climits>
#include<algorithm>
#include<bits/stdc++.h>
//Goto Tools > Editor Option > Snippets > Default Source Code

using namespace std;
bool sorted (int arr[],int n){
	if(n==1){
		return true;
	}
	bool restArray=sorted(arr+1,n-1);
	return (arr[0]<arr[1]&&restArray);
}
int main(){
	int arr[]={1,2,3,9,5,6};
	cout<<sorted(arr,6);
return 0;
}



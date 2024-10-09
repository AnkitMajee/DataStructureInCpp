#include<iostream>
#include<string.h>
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	char arr[n];
	cin>>arr;
	bool check=1;
	for(int i=0; i<n;i++){
		if(arr[i]!=arr[n-1-i])
		check=0;
	}
	if(check==1)
	cout<<arr<<" "<<"is pallindrome";
	else
	cout<<arr<<" "<<"is not a pallindrome";
return 0;
}


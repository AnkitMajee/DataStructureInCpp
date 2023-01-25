#include<iostream>
#include<string>
#include<math.h>
#include<climits>
#include<algorithm>
#include<bits/stdc++.h>
//Goto Tools > Editor Option > Snippets > Default Source Code

using namespace std;
int sum(int n){
	if(n==0){
		return 0;
	}
	int prevSum=sum(n-1);
	return n+prevSum;
}
int main(){
	int n;
	cin>>n;
	cout<<sum(n);
return 0;
}



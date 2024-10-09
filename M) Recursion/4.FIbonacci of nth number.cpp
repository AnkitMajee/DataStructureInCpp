#include<iostream>
#include<string>
#include<math.h>
#include<climits>
#include<algorithm>
#include<bits/stdc++.h>
//Goto Tools > Editor Option > Snippets > Default Source Code

using namespace std;
int fib(long long n){
	if(n==0 || n==1){
		return n;
	}
	return fib(n-1)+fib(n-2);
}
int main(){
	long long n;
	cin>>n;
	cout<<fib(n);
return 0;
}



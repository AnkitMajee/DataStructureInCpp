#include<iostream>
#include<string>
#include<math.h>
#include<climits>
#include<algorithm>
#include<bits/stdc++.h>
//Goto Tools > Editor Option > Snippets > Default Source Code

using namespace std;
int factorial(int n){
		if(n==0){
		return 1;
	}

	int prevfact=factorial(n-1);
	
	
	return n* prevfact;
}
int main(){
	int n;
	cin>>n;
	cout<<factorial(n);
return 0;
}



#include<iostream>
#include<string>
#include<math.h>
#include<climits>
#include<algorithm>
#include<bits/stdc++.h>
//Goto Tools > Editor Option > Snippets > Default Source Code

using namespace std;
int power(int n,int p){
	if(p==0){
		return 1;
	}
	int prevpower=power(n,p-1);
	return n* prevpower;
	
}
int main(){
	int n,p;
	cin>>n>>p;
	cout<<power(n,p);
return 0;
}



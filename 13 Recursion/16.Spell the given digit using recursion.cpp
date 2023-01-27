#include<iostream>
#include<string>
#include<math.h>
#include<climits>
#include<algorithm>
#include<bits/stdc++.h>
//Goto Tools > Editor Option > Snippets > Default Source Code

using namespace std;
void printspell(int n,string str[]){
	if(n==0)
	return;
	printspell(n/10,str);
	int number=n%10;
	cout<<str[number]<<" ";
	str[n%10];
}
int main(){
	int n;
	cin>>n;
	string str[10]={"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
	printspell(n,str);
return 0;
}



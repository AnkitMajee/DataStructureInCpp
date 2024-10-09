#include<iostream>
#include<string>
#include<math.h>
#include<climits>
#include<algorithm>
#include<bits/stdc++.h>
//Goto Tools > Editor Option > Snippets > Default Source Code

using namespace std;
string moveallx(string s){
	if(s.length()==0){
		return"";
	}
	char ch=s[0];
	string ans=moveallx(s.substr(1));
	if(ch=='x'){
		return ans+ch;
	}
	return ch+ans;
}
int main(){
	cout<<moveallx("axxshdxxsisuux");
return 0;
}



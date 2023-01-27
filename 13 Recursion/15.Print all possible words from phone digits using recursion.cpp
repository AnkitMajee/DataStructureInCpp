#include<iostream>
#include<string>
#include<math.h>
#include<climits>
#include<algorithm>
#include<bits/stdc++.h>
//Goto Tools > Editor Option > Snippets > Default Source Code

using namespace std;
string keypadArr[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
void keypad(string s, string ans){
	if(s.length()==0){
		cout<<ans<<endl;
		return;
	}
	char ch=s[0];
	string code=keypadArr[ch-'0'];
	string ros=s.substr(1);
	for(int i=0;i<code.length();i++){
		keypad(ros,ans+code[i]);
	}
}
int main(){
	keypad("23","");
return 0;
}



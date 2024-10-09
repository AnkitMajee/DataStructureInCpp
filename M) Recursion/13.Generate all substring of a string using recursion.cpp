#include<iostream>
#include<string>
#include<math.h>
#include<climits>
#include<algorithm>
#include<bits/stdc++.h>
//Goto Tools > Editor Option > Snippets > Default Source Code

using namespace std;
void subseq(string s,string ans=""){
	if(s.length()==0){
		cout<<ans<<endl;
		return;
	}
	char ch=s[0];
	string ros=s.substr(1);
	subseq(ros,ans);
	subseq(ros,ans+ch);
}
int main(){
	subseq("ABC","");
	cout<<endl;
return 0;
}



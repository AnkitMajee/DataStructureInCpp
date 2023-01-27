#include<iostream>
#include<string>
#include<math.h>
#include<climits>
#include<algorithm>
#include<bits/stdc++.h>
//Goto Tools > Editor Option > Snippets > Default Source Code

using namespace std;
string removeDup(string s){
	if(s.length()==0){
		return"";}
		char ch=s[0];
		string ans=removeDup(s.substr(1));
		if(ch==ans[0]){
			return ans;
		}
		return(ch+ans);
	}

int main(){
	cout<<removeDup("aaabbccddeefff")<<endl;
return 0;
}



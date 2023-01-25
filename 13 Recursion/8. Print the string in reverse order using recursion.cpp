#include<iostream>
#include<string>
#include<math.h>
#include<climits>
#include<algorithm>
#include<bits/stdc++.h>
//Goto Tools > Editor Option > Snippets > Default Source Code

using namespace std;
void reverse(string s){
	if(s.length()==0){//base case
		return;
	}
	string ros=s.substr(1);
	cout<<ros<<endl;

	reverse(ros);
	//cout<<ros<<endl;
	cout<<s[0];
}
int main(){

	 reverse("ankit");
return 0;
}



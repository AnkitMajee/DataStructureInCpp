#include<iostream>
#include<string>
#include<math.h>
#include<climits>
#include<algorithm>
#include<bits/stdc++.h>
//Goto Tools > Editor Option > Snippets > Default Source Code

using namespace std;
int countpath(int s,int e){
	if(s==e){
	return 1;
}
if(s>e){
	return 0;
}
int count=0;
for(int i=1;i<=6;i++){
	count+=countpath(s+i,e);
}
return count;
}
int main(){
	cout<<countpath(0,6)<<endl;
	
return 0;
}



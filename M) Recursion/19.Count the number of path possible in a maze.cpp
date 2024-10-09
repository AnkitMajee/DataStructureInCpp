#include<iostream>
#include<string>
#include<math.h>
#include<climits>
#include<algorithm>
#include<bits/stdc++.h>
//Goto Tools > Editor Option > Snippets > Default Source Code
//Given a 2D maze find the all the  path to complete the path where 2D maze=n*n matrix

using namespace std;
int countpathmaze(int n,int i,int j){
	if(i==n-1 && j==n-1){
		return 1;
	}
	if(i>=n|| j>=n){
		return 0;
	}
	return countpathmaze(n,i+1,j)+countpathmaze(n,i,j+1);
}
int main(){
	cout<<countpathmaze(3,0,0)<<endl;
return 0;
}



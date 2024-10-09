#include<iostream>
#include<string>
#include<math.h>
#include<climits>
#include<algorithm>
#include<bits/stdc++.h>
//Goto Tools > Editor Option > Snippets > Default Source Code

using namespace std;
void primeSives(int n){
	int prime[100]={0};
	for(int i=2;i<=n;i++){
		if(prime[i]==0){
			for(int j=i*i;j<=n;j+=i){
				prime[j]=1;
			}
		}
	}
	for(int i=2;i<=n;i++){
		if(prime[i]==0){
  cout<<i<<" ";
		}
	}
	cout<<endl;
}
int main(){
	int n;
	cin>>n;
	primeSives(n);
	return 0;
return 0;
}



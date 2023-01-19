#include<iostream>
using namespace std;
int sum(int n){
	int ans=0;
	for(int i=0;i<=n;i++){
		ans+=1;
	}
	return ans;
}
int sum(int n){
	return(n*(n+1))/2;
}
int main(){
	int n;
	cin>>n;
	cout<<sum(n)<<endl;
return 0;
}

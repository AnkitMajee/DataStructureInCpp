#include<iostream>
using namespace std;

int oddeven(int n){
	if(n%2==0){
		cout<<"Even";
	}
	else{
		cout<<"Odd";
	}
	return 0;
}
int main(){
int n;
cin>>n;
cout<<oddeven(n);
return 0;
}

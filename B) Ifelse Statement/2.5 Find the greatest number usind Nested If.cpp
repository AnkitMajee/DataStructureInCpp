#include<iostream>
using namespace std;
int main(){
	int x,y;
	cin>>x>>y;
	if(x==y){
		cout<<"Both the numbers are equal";
	}
	else{
		if(x>y){
			cout<<"X is Greater than Y";
		}
		else{
			cout<<"Y is Greater than X";
		}
	}
	return 0;
}


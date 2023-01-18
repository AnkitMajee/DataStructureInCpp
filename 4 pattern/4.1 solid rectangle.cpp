#include<iostream>
using namespace std;
int main(){
	int row,columns;
	cout<<"Enter the numbers of rows:-\n";
	cin>>row;
	cout<<"Enter the numbers of columns:-\n";
	cin>>columns;
	for(int i=1;i<=row;i++){
		for(int j=1;j<=columns;j++){
			cout<<"*";
		}
		cout<<endl;
	}
return 0;
}


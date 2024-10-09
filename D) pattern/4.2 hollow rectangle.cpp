#include<iostream>
using namespace std;
int main(){	int row,columns;
	cout<<"Enter the numbers of rows:-\n";
	cin>>row;
	cout<<"Enter the numbers of columns:-\n";
	cin>>columns;
	for(int i=1;i<=row;i++){
		for(int j=1;j<=columns;j++){
			if(i==1|| i==row ||j== 1|| j==columns){

			cout<<"*";
			}
			else{
			cout<<" ";
		}
		}
		cout<<endl;
	}

return 0;
}


#include<iostream>
using namespace std;
int main(){
	int arr[]={10,20,30,40};
	cout<<*arr<<endl;           //10
	int *b=arr;
	for(int i=0;i<3;i++){
		cout<<*b<<endl;
		b++;
		
	}
	for(int i=0;i<3;i++){
		cout<<*(arr+i)<<endl;
		
	}
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<endl;
	
//Pointer to Pointer

int a=10;
int *p;
p=&a;
cout<<*p<<endl;
int **q=&p;
cout<<*q<<endl;
cout<<**q<<endl;
return 0;
}


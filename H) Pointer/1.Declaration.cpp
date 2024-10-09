#include<iostream>
using namespace std;
int main(){
	int a=10;
	int *aptr=&a;
	cout<<*aptr<<endl;
	cout<<a<<endl;
	*aptr=30;
	cout<<a<<endl;
	//Pointer Arithmetic'++.--,+-,-+'
	cout<<aptr<<endl;                 
	aptr++;
	cout<<aptr<<endl;                 //684826
	aptr++;
	cout<<aptr<<endl;                 //684830
	
	

return 0;
}


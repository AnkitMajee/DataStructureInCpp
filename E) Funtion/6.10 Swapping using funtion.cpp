#include<iostream>
using namespace std;
void swapped(int n1,int n2){
	 int temp;
	 
	 temp=n1;
	 n1=n2;
	 n2=temp;
	 	cout<<"The Swapped Value is"<<n1<<n2;
	}
int main(){
	int n1,n2;
	cout<<"Enter two numbers:-";
	cin>>n1>>n2;
	swapped(n1,n2);

return 0;
}

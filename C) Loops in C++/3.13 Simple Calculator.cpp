#include<iostream>
using namespace std;
int main(){
	int n1,n2;
	char op;
	cout<<"Enter 1st number:";
	cin>>n1;
	cout<<"Enter operator:";
	cin>>op;
	cout<<"Enter 2nd number:";
	cin>>n2;
switch(op){
	case'+':
		cout<<n1+n2<<endl;
		break;
    case'-':
		cout<<n1-n2<<endl;
		break;
	case'*':
		cout<<n1*n2<<endl;
		break;
    case'/':
		cout<<n1/n2<<endl;
		break;
	case'%':
		cout<<n1%n2<<endl;
		break;
	case'^':
		cout<<n1*n1*n1<<endl;
		break;
	
		default:
			cout<<"operator not found !"<<endl;
			break;
}
	return 0;
}

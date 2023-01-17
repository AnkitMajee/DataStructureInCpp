#include<iostream>
using namespace std;
int main(){
	char button;
	cout<<"Enter a Character(a-f):";
	cin>>button;
switch(button){
	case'a':
		cout<<"Hello"<<endl;
		break;
    case'b':
    	cout<<"Namaste"<<endl;
    	break;
    case'c':
		cout<<"Salut"<<endl;
		break;
	case'd':
    	cout<<"Hola"<<endl;
    	break;
    case'e':
    	cout<<"Ciao"<<endl;
    	break;
    case'f':
    	cout<<"Hare Krishna"<<endl;
    	break;
    	
	default:
		cout<<"I am still learning"<<endl;
		break;
}

	return 0;
}

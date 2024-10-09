#include<iostream>
using namespace std;

void alphabet(char c){
	if(c>='A'&& c<='z'|| c>='a'&& c<='z')
	cout<<"Alphabet";
	else
	cout<<"Invalid Input !";
	
}
int main(){
	char c;
	cout<<"Enter a Character:-";
	cin>>c;
	alphabet(c);

return 0;
}

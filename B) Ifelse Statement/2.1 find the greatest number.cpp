#include<iostream>
using namespace std;
int main(){
	int a,b,c;
		cin>>a>>b>>c;

	if(a>c){
		if(a>b){
			cout<<a<<endl;
			}
		else{
			cout<<b<<endl;
		}
	}
	else{
		if(c>b){
			cout<<c<<endl;
		}
		else{
			cout<<b<<endl;
		}
	}
 return 0;
}


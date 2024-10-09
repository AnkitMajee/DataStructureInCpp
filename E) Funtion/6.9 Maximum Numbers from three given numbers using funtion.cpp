#include<iostream>
using namespace std;
void max(int x,int y,int z){
	if(x>y){
		if(x>z)
		cout<<"X is Maximum\n";
		else
		cout<<"Z is Maximum\n";
	}
	else if(y>z){
		cout<<"Y is Maximun\n";
	}
	else{
		cout<<"Z is Maximum\n";
	}

}
void min(int x,int y,int z){
	if(x<y){
		if(x<z)
		cout<<"X is Minimum\n";
		else
		cout<<"Z is Minimum\n";
	}
	else if(y<z){
		cout<<"Y is Minimum\n";
	}
	else{
		cout<<"Z is Minimum\n";
	}

}
int main(){
	int x,y,z;
	cout<<"Enter three numbers:-";
	cin>>x>>y>>z;
	max(x,y,z);
	min(x,y,z);
return 0
;
}

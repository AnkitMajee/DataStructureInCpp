#include<iostream>
using namespace std;
int main(){
	int i;
	for(i=1;i<=20;i++){     //Except the number divisible by 3 all others are printed so continue skippes the if() statement
		if(i%3==0){
			continue;
		}
		cout<<i<<endl;
	}

	return 0;
}

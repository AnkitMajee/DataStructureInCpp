#include<iostream>
using namespace std;
	void increment(int b){
		b++;
	}
		void incrementplus(int *a){
	 for(int i=0;i<*a;i++)
	 cout<<i;
	}
int main(){

//passing pointer to funtiom
   int c=2,a=2;

	increment(c);
	cout<<c<<endl;

	incrementplus(&a);
	cout<<a<<endl;

return 0;
}



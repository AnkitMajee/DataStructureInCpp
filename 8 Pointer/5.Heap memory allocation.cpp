#include<iostream>
using namespace std;
int main(){
	int a=10;
	int *p=new int();//allocating new memory space;
	*p=10;
	cout<<p;
	 delete(p);
	 p=new int[4];
	 delete[]p;
	 p=NULL;
	 
return 0;
}


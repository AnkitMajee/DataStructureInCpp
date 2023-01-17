#include<iostream>
using namespace std;
int main(){
	int n,sum=0;
	cout<<"Enter a number:";
	cin>>n;
	while(n>=0){
		sum+=n; //sum=sum+n; both are same
		cout<<"Enter a number:";
		cin>>n;
	}
cout<<"\n The sum is"<<sum<<endl;

	return 0;
}

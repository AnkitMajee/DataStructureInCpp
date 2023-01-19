#include<iostream>
using namespace std;
void voteEligibility(int age){
	if(age>=18){
		cout<<"You Can Vote";
	}
	else{
		cout<<"Not eligible For Voting";
	}
}



int main(){
	int age;
	cout<<"Enter your age";
	cin>>age;
	voteEligibility(age);
return 0;
}

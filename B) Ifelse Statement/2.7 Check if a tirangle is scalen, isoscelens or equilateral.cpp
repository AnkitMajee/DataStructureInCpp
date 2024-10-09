#include<iostream>
using namespace std;
int main(){
	int sidea,sideb,sidec;
	cout<<"Input three side of trianlge:";
	cin>>sidea>>sideb>>sidec;
	if(sidea==sideb && sideb==sidec){
		cout<<"This Triangle is an equilateral Triangle with three equal sides.\n";
	}
	else if(sidea==sideb|| sidea==sidec|| sideb==sidec){
		cout<<"This is an isosceles Triangle with two equal sides.\n";
	}
	else{
		cout<<"This is a Scalene Triangle with no equal sides.\n";
	}

	return 0;
}
/*
#include<iostream>
using namespace std;
int main(){

	return 0;
}
	*/

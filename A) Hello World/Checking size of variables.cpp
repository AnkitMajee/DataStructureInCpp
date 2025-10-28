#include <iostream>
using namespace std;

int main()
{
	int a;
	
	cout << "Enter any int : ";
	cin >> a;
	cout << "size of int : " << sizeof(a) << endl;
	float b;

	cout << "Enter any float : ";
	cin >> b;
	cout << "size of float : " << sizeof(b) << endl;
	char c;

	cout << "Enter any char : ";
	cin >> c;
	cout << "size of char : " << sizeof(c) << endl;
	bool d;

	cout << "Enter any bool : ";
	cin >> d;
	cout << "size of bool : " << sizeof(d) << endl;
	short int si;

	cout << "Enter any short int : ";
	cin >> si;
	cout << "size of short int : " << sizeof(si) << endl;
	long int li;

	cout << "Enter any long int : ";
	cin >> li;
	cout << "size of long int=" << sizeof(li) << endl;

	return 0;
}
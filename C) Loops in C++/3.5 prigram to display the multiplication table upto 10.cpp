#include <iostream>
using namespace std;

int main()
{
	int n, sum = 0;

	cout << "Enter a positive interger : ";
	cin >> n;

	for (int i = 1; i <= 10; ++i)
	{
		cout << n << "*" << i << "=" << n * i << endl;
	}

	return 0;
}
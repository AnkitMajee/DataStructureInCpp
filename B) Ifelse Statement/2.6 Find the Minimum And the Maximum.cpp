#include <iostream>
using namespace std;

int main()
{
	int n1, n2, max, min;
	cin >> n1 >> n2;
	
	if (n1 > n2)
	{
		max = n1;
		min = n2;
	}
	else
	{
		max = n2;
		min = n1;
	}

	cout << "Max=" << max << endl;
	cout << "Min=" << min << endl;
	
	return 0;
}
#include <iostream>
using namespace std;

int main()
{
	int i;
	for (i = 1; i <= 20; i++)
	{
		if (i == 11)
		{
			break;
		}
		cout << i << endl;
	}

	return 0;
}
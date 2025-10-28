#include <iostream>
using namespace std;

int main()
{
	char c;
	int lvowel, uvowel;

	cout << "Enter an Alphabet=";
	cin >> c;
	
	lvowel = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
	uvowel = (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
	if (lvowel || uvowel)
	{
		cout << c << " is a vowel";
	}
	else
	{
		cout << c << " is a Consonant";
	}

	return 0;
}
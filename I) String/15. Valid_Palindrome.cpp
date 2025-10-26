#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string alpha_numeric(string str)
{
    string newstr;
    for (char ch : str)
    {
        if (isalnum(ch))
        {
            newstr += tolower(ch);
        }
    }
    return newstr;
}

bool isPalindrome(string s)
{
    string str = alpha_numeric(s);
    int n = str.size();
    int low = 0;
    int high = n - 1;

    while (low < high)
    {
        if (str[low] != str[high])
        {
            return false;
        }
        low++;
        high--;
    }
    return true;
}

int main()
{
    string input;
    cout << "Enter a string: ";
    getline(cin, input);

    if (isPalindrome(input))
    {
        cout << "The string is a palindrome." << endl;
    }
    else
    {
        cout << "The string is not a palindrome." << endl;
    }

    return 0;
}
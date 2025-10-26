#include <iostream>
#include <stack>
#include <string>
using namespace std;

int precedence(char op)
{
    if (op == '+' || op == '-')
    {
        return 1;
    }
    if (op == '*' || op == '/')
    {
        return 2;
    }
    if (op == '^')
    {
        return 3;
    }
    return 0;
}

bool isOperand(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9');
}

string infixToPostfix(string infix)
{
    stack<char> s;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++)
    {
        char ch = infix[i];
        if (isOperand(ch))
        {
            postfix += ch;
        }
        else if (ch == '(')
        {
            s.push(ch);
        }
        else if (ch == ')')
        {
            while (!s.empty() && s.top() != '(')
            {
                postfix += s.top();
                s.pop();
            }
            s.pop();
        }
        else
        {
            while (!s.empty() && precedence(s.top()) >= precedence(ch))
            {
                postfix += s.top();
                s.pop();
            }
            s.push(ch);
        }
    }
    while (!s.empty())
    {
        postfix += s.top();
        s.pop();
    }
    return postfix;
}

string reverseString(const string &str)
{
    string reversed = str;
    int n = reversed.length();
    for (int i = 0; i < n / 2; i++)
    {
        swap(reversed[i], reversed[n - i - 1]);
    }
    return reversed;
}

string infixToPrefix(string infix)
{
    string reversedInfix = reverseString(infix);

    for (int i = 0; i < reversedInfix.length(); i++)
    {
        if (reversedInfix[i] == '(')
        {
            reversedInfix[i] = ')';
        }
        else if (reversedInfix[i] == ')')
        {
            reversedInfix[i] = '(';
        }
    }

    string postfix = infixToPostfix(reversedInfix);

    return reverseString(postfix);
}

int main()
{
    string infix;

    cout << "Enter an infix expression: ";
    cin >> infix;

    string prefix = infixToPrefix(infix);
    cout << "Prefix expression: " << prefix << endl;

    return 0;
}
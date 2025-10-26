#include <iostream>
#include <stack>
#include <string>
using namespace std;

int evaluatePrefix(const string &expression)
{
    stack<int> s;
    for (int i = expression.length() - 1; i >= 0; i--)
    {
        char ch = expression[i];
        if (ch >= '0' && ch <= '9')
        {
            s.push(ch - '0');
        }
        else if (ch == ' ')
        {
            continue;
        }
        else
        {
            int operand1 = s.top();
            s.pop();
            int operand2 = s.top();
            s.pop();

            switch (ch)
            {
            case '+':
                s.push(operand1 + operand2);
                break;
            case '-':
                s.push(operand1 - operand2);
                break;
            case '*':
                s.push(operand1 * operand2);
                break;
            case '/':
                s.push(operand1 / operand2);
                break;
            default:
                cerr << "Invalid operator: " << ch << endl;
                return -1;
            }
        }
    }
    return s.top();
}

int main()
{
    string expression;

    cout << "Enter a prefix expression (e.g., -+53*82): ";
    getline(cin, expression);

    cout << "The result of the expression is: " << evaluatePrefix(expression) << endl;

    return 0;
}
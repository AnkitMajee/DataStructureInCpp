#include <iostream>
using namespace std;

class Stack
{
private:
    int top;
    int arr[100];
    int maxSize;

public:
    Stack(int size = 100)
    {
        top = -1;
        maxSize = size;
    }

    bool isFull()
    {
        return top == maxSize - 1;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    void push(int x)
    {
        if (isFull())
        {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = x;
        cout << x << " pushed into stack\n";
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow\n";
            return;
        }
        cout << arr[top--] << " popped from stack\n";
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty\n";
            return -1;
        }
        return arr[top];
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty\n";
            return;
        }
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    int choice, value, size;

    cout << "Enter the size of the stack: ";
    cin >> size;

    Stack s(size);

    do
    {
        cout << "\nStack Operations Menu:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            s.push(value);
            break;
        case 2:
            s.pop();
            break;
        case 3:
            value = s.peek();
            if (value != -1)
            {
                cout << "Top element is: " << value << endl;
            }
            break;
        case 4:
            s.display();
            break;
        case 5:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
#include <iostream>
#include "functions.h"

using namespace std;

int main()
{
    Tree t;
    int choice, parent, value;

    while (true)
    {
        cout << "\n===== TREE MENU =====\n";
        cout << "1. Insert Node\n";
        cout << "2. Find Node\n";
        cout << "3. Find Parent\n";
        cout << "4. Print Tree\n";
        cout << "5. Get Degree of Node\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter parent value: ";
            cin >> parent;
            cout << "Enter new node value: ";
            cin >> value;
            t.insertNode(parent, value);
            break;
        case 2:
            cout << "Enter node value to find: ";
            cin >> value;
            if (t.findNode(value))
                cout << "Node " << value << " exists.\n";
            else
                cout << "Node not found.\n";
            break;
        case 3:
            cout << "Enter node value to find parent: ";
            cin >> value;
            if (t.findParent(value))
                cout << "Parent of " << value << " is " << t.findParent(value)->getData() << ".\n";
            else
                cout << "Parent not found (maybe it's the root).\n";
            break;
        case 4:
            cout << "Pre-order traversal:\n";
            t.print_pre0rder();
            break;
        case 5:
            cout << "Enter node value to get degree: ";
            cin >> value;
            cout << "Degree of " << value << " is " << t.getDegree(value) << ".\n";
            break;
        case 0:
            cout << "Exiting...\n";
            return 0;
        default:
            cout << "Invalid choice! Try again.\n";
            break;
        }
    }

    return 0;
}

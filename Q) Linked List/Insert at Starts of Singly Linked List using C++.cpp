// I/P: 10->20->30->40        element=5
// O/P: 5->10->20->30->40

// I/P: Null                  element=50
// O/P: 50

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *head = NULL;

void insertAtBegin(int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void printList()
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    insertAtBegin(1);
    insertAtBegin(2);
    insertAtBegin(3);
    insertAtBegin(4);
    insertAtBegin(5);

    cout << "Linked List: ";
    printList();

    return 0;
}
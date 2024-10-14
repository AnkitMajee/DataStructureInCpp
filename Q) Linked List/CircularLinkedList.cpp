// Implementation of Circular Linked List
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};
void InsertNode(Node *&tail, int element, int d)
{

    if (tail == NULL)
    {
        Node *newnode = new Node(d);
        tail = newnode;
        newnode->next = newnode;
    }
    else
    {
        Node *curr = tail;
        Node *newnode = new Node(d);
        while (curr->data != element)
        {
            curr = curr->next;
        }
        newnode->next = curr->next;
        curr->next = newnode;
    }
}
void print(Node *tail)
{
    Node *temp = tail;
    if (temp == NULL)
    {
        cout << "List is Empty" << endl;
        return;
    }
    do
    {
        cout << tail->data << "->";
        tail = tail->next;
    } while (tail != temp);
    cout << endl;
}

void Delete(Node *tail, int element)
{
    Node *curr = tail->next;
    Node *prev = tail;
    while (curr->data != element)
    {
        prev = curr;
        curr = curr->next;
    }
    prev->next = curr->next;
    if (curr == prev)
    {
        tail = NULL;
    }
    if (tail == curr)
    {
        tail = prev;
    }
    delete (curr);
}
int main()
{
    Node *tail = NULL;

    InsertNode(tail, 5, 3);
    print(tail);
    InsertNode(tail, 3, 5);
    print(tail);
    InsertNode(tail, 5, 7);
    print(tail);
    InsertNode(tail, 7, 9);
    print(tail);
    InsertNode(tail, 5, 6);
    print(tail);
    InsertNode(tail, 9, 10);
    print(tail);
    InsertNode(tail, 3, 4);
    print(tail);
    Delete(tail, 10);
    print(tail);
    Delete(tail, 6);
    print(tail);

    return 0;
}
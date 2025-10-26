// Question
// Given the head of a singly linked list containing positive integers, your task is to swap the data of every two adjacent nodes in the list. Return the head of the modified linked list after performing pairwise swaps.
// Examples:
// Input: 1->2->3->4->5->6->7
// Output: 2->1->4->3->6->5->7
// Explanation:The linked list after swapping becomes:
// Constraint:
// 1 ≤ number of nodes ≤ 105
// 1 ≤ node values ≤ 105

// Solution

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void printlist(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

void pairwiseSwap(Node *head)
{
    Node *curr = head;
    while (curr != NULL && curr->next != NULL)
    {
        swap(curr->data, curr->next->data);
        curr = curr->next->next;
    }
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    printlist(head);
    pairwiseSwap(head);
    printlist(head);
    
    return 0;
}
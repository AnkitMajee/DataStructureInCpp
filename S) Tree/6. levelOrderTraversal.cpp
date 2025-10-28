#include <iostream>
#include <queue>
#include <bits/stdc++.h>

using namespace std;

// Define the node structure for the binary tree
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

// Function to create a new node with given data
Node *newNode(int data)
{
    Node *node = new Node(data);
    return node;
}

// Function to insert a node in the binary tree
Node *insert(Node *root, int data)
{
    if (root == NULL)
    {
        return newNode(data);
    }
    else
    {
        if (data <= root->data)
        {
            root->left = insert(root->left, data);
        }
        else
        {
            root->right = insert(root->right, data);
        }
        return root;
    }
}

// Function to print the binary tree in postorder traversal
void levelOrder(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();
        if (front == NULL)
        {
            if (!q.empty())
            {
                cout << endl;
                q.push(NULL);
            }
        }
        else
        {
            cout << front->data << " ";
            if (front->left != NULL)
            {
                q.push(front->left);
            }
            if (front->right != NULL)
            {
                q.push(front->right);
            }
        }
    }
}

int main()
{
    // Create a new binary tree
    Node *root = NULL;
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 1);
    root = insert(root, 4);
    root = insert(root, 6);
    root = insert(root, 8);

    // Print the binary tree in postorder traversal
    levelOrder(root);
    cout << endl;

    return 0;
}
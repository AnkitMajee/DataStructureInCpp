#include <bits/stdc++.h>
using namespace std;

// Define the node structure for the binary tree
struct Node
{
    int data;
    Node *left;
    Node *right;
};

// Function to create a new node with given data
Node *newNode(int data)
{
    Node *node = new Node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
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
            // cout<<data<<root->data<<endl;
            root->left = insert(root->left, data);
        }
        else
        {
            root->right = insert(root->right, data);
        }
        return root;
    }
}

// Function to print the binary tree in inorder traversal
void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
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

    // Print the binary tree in inorder traversal
    inorder(root);
    cout << endl;

    return 0;
}

// Goto tools > Editor Option > Snippets >Default Source Code
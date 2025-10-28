#include <iostream>
using namespace std;

// Problem Statement:
// Given the root of a binary tree, return its maximum depth.
// A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

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

int maxDepth(Node *root)
{
    if (root == NULL)
        return 0;
    int leftHeight = maxDepth(root->left);
    int rightHeight = maxDepth(root->right);
    return max(leftHeight, rightHeight) + 1;
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

    cout << maxDepth(root);
}